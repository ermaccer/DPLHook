#pragma once
#include <Windows.h>


class eSettingsManager {
public:
	eSettingsManager();

	bool bEnableConsoleWindow;

	int iMenuOpenKey = VK_F1;
	int iToggleSlowMoKey;
	int iToggleHUDKey;
	int iPlayLastAnimationKey;
	int iStopLastAnimationKey;

	// free camera keys
	int iFreeCameraKeyForward;
	int iFreeCameraKeyBack;
	int iFreeCameraKeyUp;
	int iFreeCameraKeyDown;
	int iFreeCameraKeyLeft;
	int iFreeCameraKeyRight;

	int iFreeCameraKeyYawPlus;
	int iFreeCameraKeyYawMinus;
	int iFreeCameraKeyPitchPlus;
	int iFreeCameraKeyPitchMinus;
	int iFreeCameraKeyRollPlus;
	int iFreeCameraKeyRollMinus;

	int iFreeCameraKeyFOVPlus;
	int iFreeCameraKeyFOVMinus;

	float fMenuScale;

	void SaveSettings();
	void ResetKeys();

};

extern eSettingsManager* SettingsMgr;