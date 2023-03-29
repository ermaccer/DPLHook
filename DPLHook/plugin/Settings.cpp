#include "Settings.h"
#include "..\helper\eKeyboardMan.h"
#include "..\IniReader.h"

eSettingsManager* SettingsMgr = new eSettingsManager();

eSettingsManager::eSettingsManager()
{
	CIniReader ini("");
	CIniReader user("dplhook_user.ini");

	bEnableConsoleWindow = ini.ReadBoolean("Settings", "bEnableConsoleWindow", true);

	// user first
	iMenuOpenKey = user.ReadInteger("Settings", "iMenuOpenKey", -1);

	if (iMenuOpenKey == -1)
		iMenuOpenKey = ini.ReadInteger("Settings", "iMenuOpenKey", VK_F1);


	iToggleSlowMoKey = user.ReadInteger("Settings", "iToggleSlowMoKey", -1);
	iToggleHUDKey = user.ReadInteger("Settings", "iToggleHUDKey", -1);
	iPlayLastAnimationKey = user.ReadInteger("Settings", "iPlayLastAnimationKey", -1);
	iStopLastAnimationKey = user.ReadInteger("Settings", "iStopLastAnimationKey", -1);

	iFreeCameraKeyFOVPlus = user.ReadInteger("Settings", "iFreeCameraKeyFOVPlus", -1);
	if (iFreeCameraKeyFOVPlus == -1)
		iFreeCameraKeyFOVPlus = ini.ReadInteger("Settings", "iFreeCameraKeyFOVPlus", 0);

	iFreeCameraKeyFOVMinus = user.ReadInteger("Settings", "iFreeCameraKeyFOVMinus", -1);
	if (iFreeCameraKeyFOVMinus == -1)
		iFreeCameraKeyFOVMinus = ini.ReadInteger("Settings", "iFreeCameraKeyFOVMinus", 0);

	iFreeCameraKeyForward = user.ReadInteger("Settings", "iFreeCameraKeyForward", -1);
	if (iFreeCameraKeyForward == -1)
		iFreeCameraKeyForward = ini.ReadInteger("Settings", "iFreeCameraKeyForward", 0);

	iFreeCameraKeyBack = user.ReadInteger("Settings", "iFreeCameraKeyBack", -1);
	if (iFreeCameraKeyBack == -1)
		iFreeCameraKeyBack = ini.ReadInteger("Settings", "iFreeCameraKeyBack", 0);


	iFreeCameraKeyLeft = user.ReadInteger("Settings", "iFreeCameraKeyLeft ", -1);
	if (iFreeCameraKeyLeft == -1)
		iFreeCameraKeyLeft = ini.ReadInteger("Settings", "iFreeCameraKeyLeft", 0);

	iFreeCameraKeyRight = user.ReadInteger("Settings", "iFreeCameraKeyRight", -1);
	if (iFreeCameraKeyRight == -1)
		iFreeCameraKeyRight = ini.ReadInteger("Settings", "iFreeCameraKeyRight", 0);

	iFreeCameraKeyUp = user.ReadInteger("Settings", "iFreeCameraKeyUp", -1);
	if (iFreeCameraKeyUp == -1)
		iFreeCameraKeyUp = ini.ReadInteger("Settings", "iFreeCameraKeyUp", 0);

	iFreeCameraKeyDown = user.ReadInteger("Settings", "iFreeCameraKeyDown", -1);
	if (iFreeCameraKeyDown == -1)
		iFreeCameraKeyDown = ini.ReadInteger("Settings", "iFreeCameraKeyDown", 0);

	iFreeCameraKeyYawPlus = user.ReadInteger("Settings", "iFreeCameraKeyYawPlus", -1);
	if (iFreeCameraKeyYawPlus == -1)
		iFreeCameraKeyYawPlus = ini.ReadInteger("Settings", "iFreeCameraKeyYawPlus", 0);

	iFreeCameraKeyYawMinus = user.ReadInteger("Settings", "iFreeCameraKeyYawMinus", -1);
	if (iFreeCameraKeyYawMinus == -1)
		iFreeCameraKeyYawMinus = ini.ReadInteger("Settings", "iFreeCameraKeyYawMinus", 0);

	iFreeCameraKeyRollPlus = user.ReadInteger("Settings", "iFreeCameraKeyRollPlus", -1);
	if (iFreeCameraKeyRollPlus == -1)
		iFreeCameraKeyRollPlus = ini.ReadInteger("Settings", "iFreeCameraKeyRollPlus", 0);

	iFreeCameraKeyRollMinus = user.ReadInteger("Settings", "iFreeCameraKeyRollMinus", -1);
	if (iFreeCameraKeyRollMinus == -1)
		iFreeCameraKeyRollMinus = ini.ReadInteger("Settings", "iFreeCameraKeyRollMinus", 0);


	iFreeCameraKeyPitchPlus = user.ReadInteger("Settings", "iFreeCameraKeyPitchPlus", -1);
	if (iFreeCameraKeyPitchPlus == -1)
		iFreeCameraKeyPitchPlus = ini.ReadInteger("Settings", "iFreeCameraKeyPitchPlus", 0);

	iFreeCameraKeyPitchMinus = user.ReadInteger("Settings", "iFreeCameraKeyPitchMinus", -1);
	if (iFreeCameraKeyPitchMinus == -1)
		iFreeCameraKeyPitchMinus = ini.ReadInteger("Settings", "iFreeCameraKeyPitchMinus", 0);

	fMenuScale = user.ReadFloat("MenuSettings", "fMenuScale", 1.0f);

	if (fMenuScale < 1.0f)
		fMenuScale = 1.0f;

}

void eSettingsManager::SaveSettings()
{
	CIniReader user("dplhook_user.ini");
	user.WriteFloat("MenuSettings", "fMenuScale", fMenuScale);

	user.WriteInteger("Settings", "iMenuOpenKey", iMenuOpenKey);
	user.WriteInteger("Settings", "iToggleHUDKey", iToggleHUDKey);
	user.WriteInteger("Settings", "iToggleSlowMoKey", iToggleSlowMoKey);
	user.WriteInteger("Settings", "iPlayLastAnimationKey", iPlayLastAnimationKey);
	user.WriteInteger("Settings", "iStopLastAnimationKey", iStopLastAnimationKey);
	user.WriteInteger("Settings", "iFreeCameraKeyForward", iFreeCameraKeyForward);
	user.WriteInteger("Settings", "iFreeCameraKeyBack", iFreeCameraKeyBack);
	user.WriteInteger("Settings", "iFreeCameraKeyLeft", iFreeCameraKeyLeft);
	user.WriteInteger("Settings", "iFreeCameraKeyRight", iFreeCameraKeyRight);
	user.WriteInteger("Settings", "iFreeCameraKeyUp", iFreeCameraKeyUp);
	user.WriteInteger("Settings", "iFreeCameraKeyDown", iFreeCameraKeyDown);
	user.WriteInteger("Settings", "iFreeCameraKeyYawPlus", iFreeCameraKeyYawPlus);
	user.WriteInteger("Settings", "iFreeCameraKeyYawMinus", iFreeCameraKeyYawMinus);
	user.WriteInteger("Settings", "iFreeCameraKeyRollPlus", iFreeCameraKeyRollPlus);
	user.WriteInteger("Settings", "iFreeCameraKeyRollMinus", iFreeCameraKeyRollMinus);
	user.WriteInteger("Settings", "iFreeCameraKeyPitchPlus", iFreeCameraKeyPitchPlus);
	user.WriteInteger("Settings", "iFreeCameraKeyPitchMinus", iFreeCameraKeyPitchMinus);
	user.WriteInteger("Settings", "iFreeCameraKeyFOVPlus", iFreeCameraKeyFOVPlus);
	user.WriteInteger("Settings", "iFreeCameraKeyFOVMinus", iFreeCameraKeyFOVMinus);

	CIniReader ini("");
	ini.WriteBoolean("Settings", "bEnableConsoleWindow", bEnableConsoleWindow);
}

void eSettingsManager::ResetKeys()
{
	iMenuOpenKey = VK_F1;
	iFreeCameraKeyForward = VK_NUMPAD_8;
	iFreeCameraKeyBack = VK_NUMPAD_2;
	iFreeCameraKeyLeft = VK_NUMPAD_4;
	iFreeCameraKeyRight = VK_NUMPAD_6;
	iFreeCameraKeyUp = VK_NUMPAD_7;
	iFreeCameraKeyDown = VK_NUMPAD_1;

	iFreeCameraKeyYawPlus = VK_LEFT_ARROW;
	iFreeCameraKeyYawMinus = VK_RIGHT_ARROW;
	iFreeCameraKeyPitchPlus = VK_DOWN_ARROW;
	iFreeCameraKeyPitchMinus = VK_UP_ARROW;
	iFreeCameraKeyRollMinus = VK_NUMPAD_3;
	iFreeCameraKeyRollPlus = VK_NUMPAD_9;
	iFreeCameraKeyFOVPlus = 107;
	iFreeCameraKeyFOVMinus = 109;

	iToggleHUDKey = -1;
	iToggleSlowMoKey = -1;
	iPlayLastAnimationKey = -1;
	iStopLastAnimationKey = -1;
}
