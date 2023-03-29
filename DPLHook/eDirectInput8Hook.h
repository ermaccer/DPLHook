#pragma once
#include <dinput.h>
#include <Windows.h>


class eDirectInput8Hook {
public:
	static uintptr_t	ms_pFuncPtr;

	static bool ms_bInit;

	static HRESULT WINAPI GetDeviceData_Hook(IDirectInputDevice8* device, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);

	static void Hook_GetDeviceDataOne();
	static void Hook_GetDeviceDataTwo();

};