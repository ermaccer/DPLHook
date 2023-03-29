// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include "utils.h"

#include "dpl/VehicleSpecificationManager.h"
#include "dpl/VehicleManager.h"
#include "dpl/GameOverlayManager.h"
#include "dpl/Camera.h"
#include "dpl/Viewport.h"
#include "dpl/Weapon.h"
#include "dpl/Character.h"

#include "plugin/menu.h"
#include "eDirectX9Hook.h"
#include "eDirectInput8Hook.h"
#include "plugin/Settings.h"

void null() {}

void OnInitializeHook()
{
    if (SettingsMgr->bEnableConsoleWindow)
    {
        AllocConsole();
        freopen("CONIN$", "r", stdin);
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }


    printf("DPLHook::OnInitializeHook() | Begin!\n");

    eDirectX9Hook::RegisterHook(0x5E583D, 0x5E5843, Method_Reset);

    InjectHook(0x5EF47A, eDirectX9Hook::EndScene_Call);

    InjectHook(0x5677B0, eDirectInput8Hook::Hook_GetDeviceDataOne, PATCH_JUMP);
    InjectHook(0x567569, eDirectInput8Hook::Hook_GetDeviceDataTwo, PATCH_JUMP);

    Patch(0x64B484, &CGameOverlayManager::DrawHooked);
    Patch(0x64B5AC, &COverheadMap::DrawHooked);
    Patch(0x65599C, &CPCViewport::SetFOVHooked);
    Patch(0x6420DC, &CWeapon::Step);
    Patch(0x6420E0, &CWeapon::IsAutomaticHook);

    InjectHook(0x4F1B37, &CCharacter::DrawCrosshairHook);

    InjectHook(0x55AD38, &GameCamera::SetCameraMatrix_Hook);

    // patch windowed check so that wm_keydown/wm_char is not locked by dinput
    static bool bWindowed = true;

    Patch<bool*>(0x569E38 + 2, &bWindowed);
    Patch<bool*>(0x569E56 + 2, &bWindowed);


    CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(Plugin_UpdateThread), nullptr, 0, nullptr);;
}




extern "C"
{
    __declspec(dllexport) void InitializeASI()
    {
        OnInitializeHook();
    }
}
