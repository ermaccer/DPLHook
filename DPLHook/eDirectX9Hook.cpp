#include "eDirectX9Hook.h"
#include "utils.h"
#include "plugin/menu.h"
#include "font.h"
#include "eNotifManager.h"
#include "plugin/Settings.h"
#include "helper/eKeyboardMan.h"

HWND eDirectX9Hook::ms_hWindow;
WNDPROC eDirectX9Hook::ms_pWndProc;
uintptr_t eDirectX9Hook::ms_pHookJumpEndScene;
uintptr_t eDirectX9Hook::ms_pHookJumpReset;
bool eDirectX9Hook::ms_bInit;
bool eDirectX9Hook::ms_bShouldReloadFonts;

ImVec4   eDirectX9Hook::OriginalColors[ImGuiCol_COUNT];

void eDirectX9Hook::Init()
{
	ms_hWindow = 0;
	ms_pWndProc = 0;
	ms_bInit = false;
	ms_bShouldReloadFonts = false;
}

void eDirectX9Hook::RegisterHook(uintptr_t addr, uintptr_t offset, eMethodType type)
{
	switch (type)
	{
	case Method_EndScene:
		ms_pHookJumpEndScene = offset;
		InjectHook(addr, Hook_EndScene, PATCH_JUMP);
		break;
	case Method_Reset:
		ms_pHookJumpReset = offset;
		InjectHook(addr, Hook_Reset, PATCH_JUMP);
		break;
	default:
		break;
	}
}

void __declspec(naked) eDirectX9Hook::Hook_EndScene()
{
	static LPDIRECT3DDEVICE9 pDevice = 0;
	_asm {
		mov     eax, [ecx + 0x164]
		mov pDevice, eax
		pushad
	}
	EndScene(pDevice);
	_asm {
		popad
		jmp ms_pHookJumpEndScene
	}
}

void __declspec(naked) eDirectX9Hook::Hook_Reset()
{
	_asm pushad
	ImGui_ImplDX9_InvalidateDeviceObjects();
	_asm {
		popad
		mov     ecx, [eax]
		push    eax
		call    dword ptr[ecx + 0x40]
		pushad
	}
	ImGui_ImplDX9_CreateDeviceObjects();
	_asm {
		popad
		jmp	ms_pHookJumpReset
	}
}

void eDirectX9Hook::SetImGuiStyle()
{
	ImGuiStyle* style = &ImGui::GetStyle();
	style->WindowRounding = 6.0f;
	style->ItemSpacing = ImVec2(7, 5.5);
	style->FrameRounding = 2.0f;
	style->FramePadding = ImVec2(6, 4.25);

	for (int i = 0; i < ImGuiCol_COUNT; i++)
		OriginalColors[i] = style->Colors[i];

	SetColorsDefault();

	ReloadImGuiFont();
}


void eDirectX9Hook::SetColorsDefault()
{
	if (!ms_bInit)
		return;

	ImGuiStyle* style = &ImGui::GetStyle();
	for (int i = 0; i < ImGuiCol_COUNT; i++)
	{
		ImVec4 col = OriginalColors[i];

		if (i == ImGuiCol_Text || i == ImGuiCol_TextDisabled ||
			i == ImGuiCol_WindowBg || i == ImGuiCol_MenuBarBg) continue;

		float avg = (OriginalColors[i].x + OriginalColors[i].y + OriginalColors[i].z) / 3;
		style->Colors[i] = { avg, avg,avg , col.w };
	}
}

void eDirectX9Hook::SetColors78()
{
	if (!ms_bInit)
		return;

	ImGuiStyle* style = &ImGui::GetStyle();

	// 76
	for (int i = 0; i < ImGuiCol_COUNT; i++)
	{
		ImVec4 col = OriginalColors[i];
		style->Colors[i] = { col.z * 1.25f, col.y, col.x, col.w };
	}
}

void eDirectX9Hook::SetColors06()
{
	if (!ms_bInit)
		return;

	ImGuiStyle* style = &ImGui::GetStyle();

	for (int i = 0; i < ImGuiCol_COUNT; i++)
	{
		ImVec4 col = OriginalColors[i];
		style->Colors[i] = { col.x * 1.15f, col.y * 1.15f, col.z * 1.35f, col.w };
	}
}

void eDirectX9Hook::InitImGui(LPDIRECT3DDEVICE9 pDevice)
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(ms_hWindow);
	ImGui_ImplDX9_Init(pDevice);
	SetImGuiStyle();
}

void eDirectX9Hook::ReloadImGuiFont()
{
	float fontSize = 16.0f;
	ImGuiStyle* style = &ImGui::GetStyle();
	ImGuiIO io = ImGui::GetIO();
	io.Fonts->Clear();
	io.Fonts->AddFontFromMemoryCompressedTTF(Font_compressed_data, Font_compressed_size, fontSize * SettingsMgr->fMenuScale);
	io.Fonts->Build();
	ImGui_ImplDX9_InvalidateDeviceObjects();

	if (ms_bShouldReloadFonts)
		ms_bShouldReloadFonts = false;
}

HRESULT __fastcall eDirectX9Hook::EndScene_Call(int Viewport)
{
	static LPDIRECT3DDEVICE9 pDevice = *(LPDIRECT3DDEVICE9*)(Viewport + 356);
	EndScene(pDevice);
	return ((HRESULT(__thiscall*)(int))0x5E455B)(Viewport);
}

void __stdcall eDirectX9Hook::EndScene(LPDIRECT3DDEVICE9 pDevice)
{
	if (!ms_bInit)
	{
		D3DDEVICE_CREATION_PARAMETERS params;
		pDevice->GetCreationParameters(&params);
		ms_hWindow = params.hFocusWindow;
		ms_pWndProc = (WNDPROC)SetWindowLongPtr(ms_hWindow, GWL_WNDPROC, (LONG_PTR)WndProc);
		InitImGui(pDevice);

		ms_bInit = true;
	}

	if (ms_bShouldReloadFonts)
		ReloadImGuiFont();

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::GetIO().MouseDrawCursor = false;

	static bool draw = true;
	if (draw)
	{
		Notifications->SetNotificationTime(3500);
		Notifications->PushNotification("DPLHook %s is running! Press %s to open the menu. Build date: %s", DPLHOOK_VERSION, eKeyboardMan::KeyToString(SettingsMgr->iMenuOpenKey), __DATE__);
		draw = false;
	}
	Notifications->Draw();
	TheMenu->Draw();


	ImGui::EndFrame();

	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

LRESULT __stdcall eDirectX9Hook::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KILLFOCUS:
		TheMenu->m_bIsFocused = false;
		break;
	case WM_SETFOCUS:
		TheMenu->m_bIsFocused = true;
		break;
	case WM_KEYDOWN:
		if (wParam == SettingsMgr->iMenuOpenKey)
			TheMenu->OnActivate();
		if (wParam == SettingsMgr->iToggleHUDKey)
			TheMenu->OnToggleHUD();
		if (wParam == SettingsMgr->iToggleSlowMoKey)
			TheMenu->OnToggleSlowMotion();
		if (wParam == SettingsMgr->iPlayLastAnimationKey)
			TheMenu->OnActivatePlayLastAnim();
		if (wParam == SettingsMgr->iStopLastAnimationKey)
			TheMenu->OnActivateStopLastAnim();
		if (wParam == SettingsMgr->iToggleFreeCameraKey)
			TheMenu->OnToggleFreeCam();
		break;
	default:
		break;
	}
	if (TheMenu->m_bIsActive)
	{
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
		return true;
	}


	return CallWindowProc(ms_pWndProc, hWnd, uMsg, wParam, lParam);
}