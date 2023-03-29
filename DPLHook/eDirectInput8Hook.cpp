#include "eDirectInput8Hook.h"
#include <iostream>
#include "plugin/menu.h"
#include "eDirectX9Hook.h"
#include "utils.h"

bool eDirectInput8Hook::ms_bInit;
uintptr_t	eDirectInput8Hook::ms_pFuncPtr;

HRESULT __stdcall eDirectInput8Hook::GetDeviceData_Hook(IDirectInputDevice8* device, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	HRESULT result = ((HRESULT(__stdcall*)(IDirectInputDevice8*, DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD))ms_pFuncPtr)(device, cbObjectData, rgdod, pdwInOut, dwFlags);
	if (TheMenu->m_bIsActive)
	{
		if (rgdod && cbObjectData == 20)
		{
			switch (rgdod->dwOfs)
			{
			case  DIMOFS_Z:
				if (eDirectX9Hook::ms_bInit)
				{
					ImGuiIO& io = ImGui::GetIO();
					int param;
					float y_wheel;
					y_wheel = 0.0f;
					param = rgdod->dwData;
					if (param < 0)
						y_wheel = -1.0f;
					if (param > 0)
						y_wheel = 1.0f;
					io.AddMouseWheelEvent(0.0f, y_wheel);
				}
				break;
			default:
				break;
			}

		}
		return E_FAIL;
	}


	return result;
}

void __declspec(naked) eDirectInput8Hook::Hook_GetDeviceDataOne()
{
	static int jmp_continue = 0x5677B6;
	_asm {

		mov ecx, [eax]
		pushad 
		mov ebp, dword ptr[ecx + 0x28]
		mov ms_pFuncPtr, ebp
		popad
		push eax

		call GetDeviceData_Hook
		jmp jmp_continue
	}
}

void __declspec(naked)eDirectInput8Hook::Hook_GetDeviceDataTwo()
{
	static int jmp_continue = 0x56756F;
	_asm {
		pushad
		mov ebp, dword ptr[ecx + 0x28]
		mov ms_pFuncPtr, ebp
		popad
		push    edx
		push    edi
		push    eax

		call GetDeviceData_Hook
		jmp jmp_continue
	}
}
