#include "menu.h"
#include <iostream>
#include <Windows.h>
#include <vector>

#include "Settings.h"
#include "..\eDirectX9Hook.h"
#include "..\eNotifManager.h"
#include "..\helper\eKeyboardMan.h"

#include "..\imgui\imgui.h"

#include "..\dpl\VehicleSpecificationManager.h"
#include "..\dpl\VehicleManager.h"
#include "..\dpl\LifeInstances.h"
#include "..\dpl\common.h"
#include "..\dpl\LifeSystem.h"
#include "..\dpl\LifeAcquirableVehicleManager.h"
#include "..\dpl\CharacterCategoryManager.h"
#include "..\dpl\Camera.h"
#include "..\dpl\AnimSystem.h"
#include "..\dpl\AnimLib.h"
#include "..\dpl\ResourceManager.h"
#include "..\dpl\LifeEnvironment.h"
#include "..\dpl\LifeProgression.h"
#include "..\dpl\Speed.h"
#include "..\dpl\ProfileSettings.h"
#include "..\dpl\AIFelonySystemFelonyManager.h"
#include "..\core\Vector.h"

#include "..\utils.h"




std::vector<TeleporterPlace> vTeleports;

DPLMenu* TheMenu = new DPLMenu();


static const char* szVehicles[] = {
	"BX-9",
	"BX-9 Racer",
	"Antilli VO3",
	"Atlus",
	"Atlus Racer",
	"Saxon",
	"Saxon Cargo Trailer",
	"Saxon Flatbed Trailer",
	"Saxon Tanker Trailer",
	"Colonna",
	"Colonna Racer",
	"M700",
	"Hotrod",
	"Indiana",
	"Kramer",
	"Kramer Racer",
	"Miyagi",
	"Montara",
	"Mutsumi 1000R",
	"MX2000",
	"MX2000 Racer",
	"Negotiator",
	"Torrex",
	"Torrex Racer",
	"Olympic",
	"Paramedic",
	"Prestige",
	"Prestige Racer",
	"Boltus",
	"Schweizer",
	"Schweizer Racer",
	"Security Van",
	"Teramo",
	"Teramo Racer",
	"Zenda",
	"Zenda Racer",
	"Cerva",
	"Cerva Racer",
	"Bonsai",
	"Bonsai Racer",
	"Brooklyn",
	"Brooklyn Racer",
	"Bus",
	"Chauffeur",
	"Chopper",
	"Zartex",
	"Courier",
	"Cerrano",
	"Cerrano Racer",
	"Delivery Van",
	"Dolva",
	"Dolva Flatbed",
	"Dozer",
	"Andec",
	"Andec Racer",
	"Eurotech Lifter (crashes)",
	"Fairview",
	"Firetruck",
	"Grand Valley",
	"Boldius",
	"Land Roamer",
	"Meat Wagon",
	"Melizzano",
	"Melizzano Racer",
	"Raven",
	"Raven Racer",
	"Refuse Truck",
	"Regina",
	"Regina Racer",
	"Rhapsody",
	"Rosalita",
	"San Marino",
	"San Marino Racer",
	"San Marino Spyder",
	"San Marino Spyder Racer",
	"School Bus",
	"Namorra",
	"Pangea",
	"Wayfarer",
	"Wingar",
	"Woody",
	"Wrecker",
	"Yamashita 900",
	"Mission Truck",
	"Prison Bus",
	"Ram Raider",
	"Prison Van",
	"Pimp Wagon",
	"The Mexican's Ride",
	"SWAT Van",
	"Antilli VO3 Special",
	"Cerva Punk",
	"Brooklyn Punk",
	"Cerrano Punk",
	"Andec Punk",
	"Olympic Punk",
	"Torrex Turbo",
	"Wayfarer Turbo",
};

static const char* szWeapons[] = {
	"Revolver",
	"Glock",
	"44H",
	"Service9",
	"LI15",
	"Shotgun",
	"Grenade",
	"Beretta",
	"Gangster",
	"F70",
	"SF10",
	"AustPUP",
	"Shotgun06",
	"RPG",
	"Blaine"
};

static const char* szCharacters[] = {
	"Worker01_Then",
	"Worker02_Then",
	"Worker03_Then",
	"TheDriver_Now",
	"Upp_W01_Then",
	"Trucker_Then",
	"Merc01_Then",
	"Merc02_Then",
	"Merc03_Then",
	"Merc04_Then",
	"Merc05_Then",
	"Low_W04_Then",
	"Low_W03_Then",
	"Low_W02_Then",
	"Low_W01_Then",
	"Hippy01_Then",
	"Hippy02_Then",
	"Hippy03_Then",
	"C01_Then",
	"C02_Then",
	"Beatnik01_Then",
	"Beatnik02_Then",
	"B03_Then",
	"B01_Then",
	"TheKid_Then",
	"Candy_Now",
	"Bishop_Then",
	"Prisoner01_Then",
	"Prisoner02_Then",
	"Prisoner03_Then",
	"Swat01_Then",
	"Security05_Then",
	"Security04_Then",
	"Security03_Then",
	"Security02_Then",
	"Security01_Then",
	"Cop05_Then",
	"Cop04_Then",
	"Cop03_Then",
	"Cop02_Then",
	"Cop01_Then",
	"UCW03_Now",
	"UCW01_Now",
	"Biker01_Now",
	"Biker02_Now",
	"B01_Now",
	"SG01_Now",
	"SG02_Now",
	"SG03_Now",
	"SG04_Now",
	"SG05_Now",
	"MIB01_Now",
	"MIB02_Now",
	"MIB03_Now",
	"CRivals03_Now",
	"CRivals01_Now",
	"CRivals02_Now",
	"CRivals04_Now",
	"CG01_Now",
	"CG02_Now",
	"CG03_Now",
	"CG04_Now",
	"CG05_Now",
	"BGang01_Now",
	"BGang02_Now",
	"BGang03_Now",
	"Hitman01_Now",
	"Cop02_Now",
	"Cop03_Now",
	"Cop01_Now",
	"Ray_Then",
	"TheMexican_Then",
	"RWF02_Then",
	"RWF01_Then",
	"RBF01_Then",
	"PB01_Then",
	"PB02_Then",
	"PB03_Then",
	"Pimp01_Then",
	"Pimp02_Then",
	"Liquor01_Then",
	"TheKidOnline_Then",
	"RafMartinez_Then",
	"CandyPrison_Then",
	"Candy_Then",
	"Col_Goon01_Then",
	"Col_Goon02_Then",
	"Col_Goon03_Then",
	"Col_Goon04_Then",
	"Col_Goon05_Then",
	"Biker01_Then",
	"Biker02_Then",
	"Biker03_Then",
	"UCW02_Now",
	"RWMale_Now",
	"PWMale_Now",
	"PWFemale_Now",
	"PBMale_Now",
	"MCWMale_Now",
	"Low_W03_Now",
	"Low_W01_Now",
	"CMale_Now",
	"CFemale_Now",
	"B02_Now",
	"Upp_W05_Then",
	"Swat_Now",
	"tourist02_now",
	"mcwfemale_now",
	"tourist01_now",
	"his01_now",
	"his02_now",
	"homeless01_now",
	"homeless02_now",
	"jogger01_now",
	"low_w02_now",
	"rwfemale_now",
	"corrigan_then",
	"business01_then",
	"business02_then",
	"hooker01_then",
	"hooker02_then",
	"pbfemale01_then",
	"pbfemale02_then",
	"tourist03_now",
	"business01_now",
	"business02_now",
	"tourist04_now",
	"jogger02_now",
	"rwmale01_then",
	"hooker01_now",
	"prisonguard01_now",
	"prisonguard02_now",
	"rwmale02_then",
	"hooker02_now",
	"worker01_now",
	"pimp01_now",
	"worker02_now",
	"fped01_then",
	"fped02_then",
	"fped03_then",
	"fped04_then",
	"streetgang01_now",
	"thedriver_online_now",
	"streetgang02_now",
	"bishop_now",
	"corrigan_now",
	"mariacortez_now",
	"ray_now",
	"themexican_now",
	"spunk01_then",
	"spunk02_then",
	"spunk03_then",
	"spunk04_then",
	"spunk05_then",
	"hooker03_then",
	"mcb02_then",
	"mcb01_then",
	"businesswoman02_then",
	"businesswoman01_then",
	"oworker02_now",
	"oworker01_now",
	"wtstudent02_now",
	"wtstudent01_now",
	"phmale_now",
	"phfemale_now",
	"mcbmale_now",
	"mcbfemale_now",
	"bsgang02_now",
	"bsgang01_now",
	"pimp02_now",
	"trucker02_now",
	"trucker01_now",
	"businessw02_now",
	"businessw01_now",
	"mcb02_now",
	"mcb01_now",
	"cfemale01_then",
	"slink_then",
	"slink_now",
	"rbf02_then",
	"cmale01_then",
	"jogger01_then",
};

static void ShowHelpMarker(const char* desc)
{
	ImGui::TextDisabled("(?)");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}

}


DPLMenu::DPLMenu()
{
	sprintf(vehicle, szVehicles[0]);
	sprintf(weapon, szWeapons[0]);
	sprintf(animation, szAnimations[0]);
	m_vecCamRotation.X = 0;
	m_vecCamRotation.Y = 0;
	m_vecCamRotation.Z = 0;
	m_vecPlrPosition.X = 0;
	m_vecPlrPosition.Y = 0;
	m_vecPlrPosition.Z = 0;

	LoadLocationFile();

	if (vTeleports.size() > 0)
		sprintf(teleportName, vTeleports[0].name);
}

void DPLMenu::OnActivate()
{
	m_bIsActive ^= 1;
}

void DPLMenu::OnActivateSlowMotion()
{
	if (m_bSlowMotion)
		speed::SetMasterSpeedMultiplier(m_fSlowMotionSpeed);
	else
		speed::SetMasterSpeedMultiplier(1.0f);
}

void DPLMenu::OnActivatePlayLastAnim()
{
	if (!GetLifeSystem())
		return;

	CCharacter* plrChr = GetLifeSystem()->GetPlayer()->GetDriverBehaviour()->GetCharacter();

	if (!plrChr)
		return;

	if (strlen(animation) > 0)
		plrChr->PlayMissionAnimation(HashAnimName(animation), true);
}

void DPLMenu::OnActivateStopLastAnim()
{
	if (!GetLifeSystem())
		return;

	CCharacter* plrChr = GetLifeSystem()->GetPlayer()->GetDriverBehaviour()->GetCharacter();

	if (!plrChr)
		return;

	plrChr->KillMissionAnimations();
}

void DPLMenu::OnToggleSlowMotion()
{
	m_bSlowMotion ^= 1;
	OnActivateSlowMotion();
}

void DPLMenu::OnToggleHUD()
{
	m_bDisableHUD ^= 1;
}

void DPLMenu::OnToggleInvincibility()
{
	if (!GetProfileSettings())
		return;
	CProfileSettings* p = GetProfileSettings();

	p->SetCheatStatus(eCheat_Invincibility, TheMenu->m_bInvincibility);

}

void DPLMenu::OnToggleInvincibilityCars()
{
	if (!GetProfileSettings())
		return;
	CProfileSettings* p = GetProfileSettings();

	p->SetCheatStatus(eCheat_IndestructableCars, TheMenu->m_bInvicibilityCars);
}

void DPLMenu::OnToggleInfiniteNitro()
{
	if (!GetProfileSettings())
		return;
	CProfileSettings* p = GetProfileSettings();

	p->SetCheatStatus(eCheat_InfiniteNitro, TheMenu->m_bInfiniteNitro);
}

void DPLMenu::Draw()
{
	if (!m_bIsActive)
		return;

	ImGui::GetIO().MouseDrawCursor = true;
	ImGui::Begin("DPLHook by ermaccer", &m_bIsActive, ImGuiWindowFlags_MenuBar);
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("Settings"))
			{
				m_bSubmenuActive[SM_Settings] = true;
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Help"))
			{
				if (ImGui::BeginMenu("About"))
				{
					ImGui::MenuItem("Version: " DPLHOOK_VERSION);
					ImGui::MenuItem("Date: " __DATE__);
					ImGui::EndMenu();
				}

				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}

		if (GetLifeSystem())
		{
			if (ImGui::BeginTabBar("##tabs"))
			{
				if (ImGui::BeginTabItem("Player"))
				{
					DrawPlayerTab();
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Vehicles"))
				{
					DrawVehicleTab();
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Teleporter"))
				{
					DrawTeleporterTab();
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Camera"))
				{
					DrawCameraTab();
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Speed"))
				{
					DrawSpeedTab();
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("World"))
				{
					DrawWorldTab();
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Cheats"))
				{
					DrawCheatsTab();
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Weapon Editor"))
				{
					DrawWeaponEditTab();
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Misc."))
				{
					DrawMiscTab();
					ImGui::EndTabItem();
				}
				ImGui::EndTabBar();
			}
		}
		else
			ImGui::Text("Not ready!");
	
	}
	ImGui::End();


	if (m_bSubmenuActive[SM_Settings])
		DrawSettings();
}

void DPLMenu::Update()
{
	UpdateKeys();

	if (!GetLifeSystem())
		return;

	if (!GetLifeSystem()->GetPlayer())
		return;

	if (!GetLifeSystem()->GetPlayer()->GetDriverBehaviour())
		return;


	UpdateCheats();

	if (m_bSlowMotion)
		speed::SetMasterSpeedMultiplier(m_fSlowMotionSpeed);

	UpdateFreeCamera();



	if (!m_bAirbreak)
	{
		Vector4 pos;
		GetLifeSystem()->GetPlayer()->GetDriverBehaviour()->GetCharacter()->GetPosition(&pos);
		m_vecPlrPosition.X = pos.X;
		m_vecPlrPosition.Y = pos.Y;
		m_vecPlrPosition.Z = pos.Z;
	}
	else
		UpdateAirBreak();

}

void DPLMenu::UpdateKeys()
{
	if (m_bPressingKey)
		return;

	if (GetAsyncKeyState(SettingsMgr->iMenuOpenKey) & 0x1)
		TheMenu->OnActivate();
	if (GetAsyncKeyState(SettingsMgr->iToggleHUDKey) & 0x1)
		TheMenu->OnToggleHUD();
	if (GetAsyncKeyState(SettingsMgr->iToggleSlowMoKey) & 0x1)
		TheMenu->OnToggleSlowMotion();
	if (GetAsyncKeyState(SettingsMgr->iPlayLastAnimationKey) & 0x1)
		TheMenu->OnActivatePlayLastAnim();
	if (GetAsyncKeyState(SettingsMgr->iStopLastAnimationKey) & 0x1)
		TheMenu->OnActivateStopLastAnim();
}

void DPLMenu::UpdateFreeCamera()
{
	Vector fwd = m_mCameraMatrix.forward;
	Vector right = m_mCameraMatrix.right;

	static XMVECTOR defaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	static XMVECTOR defaultUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	static XMVECTOR defaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);

	if (m_bFreeCam)
	{
		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyForward))
			m_mCameraMatrix.pos += fwd * TheMenu->m_fFreeCamSpeed * GetDeltaTime() * -1;
		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyBack))
			m_mCameraMatrix.pos += fwd * TheMenu->m_fFreeCamSpeed * GetDeltaTime() * 1;

		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyLeft))
			m_mCameraMatrix.pos += right * TheMenu->m_fFreeCamSpeed * GetDeltaTime() * -1;
		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyRight))
			m_mCameraMatrix.pos += right * TheMenu->m_fFreeCamSpeed * GetDeltaTime() * 1;

		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyUp))
			m_mCameraMatrix.pos.Y += TheMenu->m_fFreeCamSpeed * GetDeltaTime() * 1;
		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyDown))
			m_mCameraMatrix.pos.Y += TheMenu->m_fFreeCamSpeed * GetDeltaTime() * -1;


		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyPitchPlus))
			m_vecCamRotation.X -= TheMenu->m_fFreeCamRotationSpeed * GetDeltaTime();
		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyPitchMinus))
			m_vecCamRotation.X += TheMenu->m_fFreeCamRotationSpeed * GetDeltaTime();

		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyYawPlus))
			m_vecCamRotation.Y += TheMenu->m_fFreeCamRotationSpeed * GetDeltaTime();
		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyYawMinus))
			m_vecCamRotation.Y -= TheMenu->m_fFreeCamRotationSpeed * GetDeltaTime();

		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyRollPlus))
			m_vecCamRotation.Z += TheMenu->m_fFreeCamRotationSpeed * GetDeltaTime();
		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyRollMinus))
			m_vecCamRotation.Z -= TheMenu->m_fFreeCamRotationSpeed * GetDeltaTime();

		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyFOVMinus))
			m_fCamFOV -= 10.0f * GetDeltaTime();
		if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyFOVPlus))
			m_fCamFOV += 10.0f * GetDeltaTime();
	}

	if (m_bCustomCameraRot)
	{
		XMMATRIX rotMat = XMMatrixRotationRollPitchYaw(m_vecCamRotation.X, m_vecCamRotation.Y, m_vecCamRotation.Z);
		XMVECTOR camLookAt = XMVector3TransformCoord(defaultForward, rotMat);
		XMVECTOR camUp = XMVector3TransformCoord(defaultUp, rotMat);
		XMVECTOR camRight = XMVector3TransformCoord(defaultRight, rotMat);
		XMVector3Normalize(camLookAt);
		XMVector3Normalize(camUp);
		XMVector3Normalize(camRight);
		XMFLOAT3 cL, cU, cR;
		XMStoreFloat3(&cL, camLookAt);
		XMStoreFloat3(&cU, camUp);
		XMStoreFloat3(&cR, camRight);

		m_mCameraMatrix.forward = { cL.x, cL.y, cL.z };
		m_mCameraMatrix.up = { cU.x, cU.y, cU.z };
		m_mCameraMatrix.right = { cR.x, cR.y, cR.z };
	}	
}


void DPLMenu::UpdateAirBreak()
{
	CCharacter* plrChr = GetLifeSystem()->GetPlayer()->GetDriverBehaviour()->GetCharacter();

	if (!plrChr)
		return;
	
	Matrix* plrMat = plrChr->GetMatrix();
	Vector fwd = GameCamera::GetInstance()->camMatrix.forward;
	Vector right = GameCamera::GetInstance()->camMatrix.right;

	if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyForward))
		m_vecPlrPosition += fwd * TheMenu->m_fAirbreakSpeed * GetDeltaTime() * -1;
	if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyBack))
		m_vecPlrPosition += fwd * TheMenu->m_fAirbreakSpeed * GetDeltaTime() * 1;

	if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyLeft))
		m_vecPlrPosition += right * TheMenu->m_fAirbreakSpeed * GetDeltaTime() * -1;
	if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyRight))
		m_vecPlrPosition += right * TheMenu->m_fAirbreakSpeed * GetDeltaTime() * 1;

	if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyUp))
		m_vecPlrPosition.Y += TheMenu->m_fAirbreakSpeed * GetDeltaTime() * 1;
	if (GetAsyncKeyState(SettingsMgr->iFreeCameraKeyDown))
		m_vecPlrPosition.Y += TheMenu->m_fAirbreakSpeed * GetDeltaTime() * -1;

	Vector4 newPos(m_vecPlrPosition.X, m_vecPlrPosition.Y, m_vecPlrPosition.Z);
	plrChr->SetPosition(&newPos);
}

void DPLMenu::UpdateColors()
{
	if (!GetCCM())
	{
		eDirectX9Hook::SetColorsDefault();
		m_nLastEra = -1;
		return;
	}

	CCharacterCategoryManager* ccm = GetCCM();
	m_nLastEra = m_nCurrentEra;
	m_nCurrentEra = ccm->GetEra();

	if (m_nLastEra != m_nCurrentEra)
	{
		if (m_nCurrentEra == CCM_Era_Then)
			eDirectX9Hook::SetColors78();
		else if (m_nCurrentEra == CCM_Era_Now)
			eDirectX9Hook::SetColors06();
	}
}

void DPLMenu::UpdateCheats()
{
	AIFelonySystemFelonyManagerClass* felony = GetFelonyManager();
	if (felony)
	{
		CCharacter* plrChr = GetLifeSystem()->GetPlayer()->GetDriverBehaviour()->GetCharacter();

		if (plrChr)
		{
			if (TheMenu->m_bMaxFelony)
				felony->SetFelonyLevel(plrChr, 0, 1.0f);
			if (TheMenu->m_bZeroFelony)
				felony->SetFelonyLevel(plrChr, 0, 0.0f);

			CVehicle* plrCar = plrChr->GetVehicle();
			if (plrCar)
			{
				if (TheMenu->m_bMaxCarFelony)
					felony->SetVehicleFelonyLevel(plrCar, 0, 1.0f);
				if (TheMenu->m_bZeroCarFelony)
					felony->SetVehicleFelonyLevel(plrCar, 0, 0.0f);
			}

		}
	}
	if (!GetProfileSettings())
		return;
	CProfileSettings* p = GetProfileSettings();
	if (TheMenu->m_bInfiniteMoney)
		p->SetMoney(999999);

	if (TheMenu->m_bInvincibility)
		p->SetCheatStatus(eCheat_Invincibility, true);
	if (TheMenu->m_bInvicibilityCars)
		p->SetCheatStatus(eCheat_IndestructableCars, true);
	if (TheMenu->m_bInfiniteNitro)
		p->SetCheatStatus(eCheat_InfiniteNitro, true);
}

void DPLMenu::DrawPlayerTab()
{
	CCharacter* plrChr = GetLifeSystem()->GetPlayer()->GetDriverBehaviour()->GetCharacter();

	if (!plrChr)
		return;

#ifdef _DEBUG
	ImGui::Text("PLR %p", plrChr);
	ImGui::Text("DB %p", GetLifeSystem()->GetPlayer()->GetDriverBehaviour());
	ImGui::Text("P %p", GetLifeSystem()->GetPlayer());
#endif


	Vector4 pos;
	plrChr->GetPosition(&pos);
	ImGui::Text("Position (X | Y | Z)");
	ImGui::SameLine();	ShowHelpMarker("Read only");

	ImGui::PushItemWidth(-FLT_MIN);
	ImGui::InputFloat3("", &pos.X);
	ImGui::PopItemWidth();

	ImGui::Separator();
	if (!plrChr->GetVehicle())
	{
		ImGui::Checkbox("Airbreak", &m_bAirbreak);
		ImGui::SameLine();
		ShowHelpMarker("Allows to move player with free camera hotkeys. Use the invincibility cheat to disable any damage!");
		if (m_bAirbreak)
		{
			ImGui::InputFloat("Airbreak Speed", &m_fAirbreakSpeed);
		}
	}
	else
		ImGui::Text("Leave the vehicle to use airbreak.");
	ImGui::Separator();

	if (ImGui::CollapsingHeader("Model"))
	{
		static int nModel = 29;
		ImGui::TextWrapped("Character ID");
		ImGui::PushItemWidth(-FLT_MIN);
		ImGui::InputInt("##mid", &nModel);
		ImGui::PopItemWidth();
		if (nModel < 1)
			nModel = 1;
		if (ImGui::Button("Set Model", { -FLT_MIN, 0 }))
		{
			SetPlayerModel(nModel);
		}

		if (ImGui::Button("Unload Model", { -FLT_MIN, 0 }))
		{
			GetResourceManager()->SetEntityPriority(2, nModel, 0);
		}
		ImGui::TextWrapped("Manually unload any non pedestrian player model before changing to new one to not overload character buffer!");
		ImGui::TextWrapped("Character Animset ID");
		ImGui::PushItemWidth(-FLT_MIN);
		ImGui::InputInt("##aid", plrChr->GetAnimTypePointer());
		ImGui::PopItemWidth();
	}
	if (ImGui::CollapsingHeader("Weapons"))
	{
		ImGui::PushItemWidth(-FLT_MIN);
		if (ImGui::BeginCombo("##wlist", weapon))
		{
			for (int n = 0; n < IM_ARRAYSIZE(szWeapons); n++)
			{
				bool is_selected = (weapon == szWeapons[n]);
				if (ImGui::Selectable(szWeapons[n], is_selected))
					sprintf(weapon, szWeapons[n]);
				if (is_selected)
					ImGui::SetItemDefaultFocus();

			}
			ImGui::EndCombo();
		}
		ImGui::PopItemWidth();
		if (ImGui::Button("Give Weapon", { -FLT_MIN, 0 }))
		{
			GiveWeaponToPlayer(GetWIDFromName(weapon));
			Notifications->SetNotificationTime(2500);
			Notifications->PushNotification("Weapon %s given!", weapon);
		}
		if (ImGui::Button("Remove All Weapons", { -FLT_MIN, 0 }))
		{
			if (!plrChr->GetVehicle())
			{
				CPlayerDriverBehaviour* player = GetLifeSystem()->GetPlayer()->GetDriverBehaviour();

				CCharacterWeapons* weaps = player->GetWeapons();
				weaps->ClearAllWeapons();
				Notifications->SetNotificationTime(2500);
				Notifications->PushNotification("Weapons removed!");
			}
			else
			{
				Notifications->SetNotificationTime(2500);
				Notifications->PushNotification("Leave the vehicle first!");
			}

		}
	}
	if (ImGui::CollapsingHeader("Animation"))
	{
		static bool manualWrite;
		ImGui::Checkbox("Enter Name", &manualWrite);

		if (manualWrite)
		{
			ImGui::PushItemWidth(-FLT_MIN);
			ImGui::InputText("##aname", animation, sizeof(animation));
			ImGui::PopItemWidth();
		}
		else 
		{
			ImGui::PushItemWidth(-FLT_MIN);
			if (ImGui::BeginCombo("##alist", animation))
			{
				for (int n = 0; n < IM_ARRAYSIZE(szAnimations); n++)
				{
					bool is_selected = (animation == szAnimations[n]);
					if (ImGui::Selectable(szAnimations[n], is_selected))
						sprintf(animation, szAnimations[n]);
					if (is_selected)
						ImGui::SetItemDefaultFocus();

				}
				ImGui::EndCombo();
			}
			ImGui::PopItemWidth();
		}

		if (ImGui::Button("Play Animation", { -FLT_MIN, 0 }))
		{
			plrChr->PlayMissionAnimation(HashAnimName(animation), true);
		}
		if (ImGui::Button("Stop Animation", { -FLT_MIN, 0 }))
		{
			plrChr->KillMissionAnimations();
		}

	}


	if (ImGui::CollapsingHeader("Player Vehicle"))
	{
		CVehicle* currentCar = plrChr->GetVehicle();
		if (currentCar)
		{
			ImGui::ColorEdit3("Color", (float*)((int)currentCar + 140));
			ImGui::Separator();
			if (ImGui::Button("Fix", { -FLT_MIN, 0 }))
			{
				float R = *(float*)((int)currentCar + 140);
				float G = *(float*)((int)currentCar + 144);
				float B = *(float*)((int)currentCar + 148);
				currentCar->ResetDamage();
				currentCar->SetColor(R, G, B);
			}
				
			if (ImGui::Button("Explode", { -FLT_MIN, 0 }))
			{
				currentCar->Kaboom();
				currentCar->Explode();
			}
			if (ImGui::Button("Give Infinite Mass", { -FLT_MIN, 0 }))
			{
				currentCar->MakeInfiniteMass();
			}
		}
		else
			ImGui::Text("Enter a vehicle.");

	}
	if (ImGui::CollapsingHeader("Status"))
	{
		if (plrChr)
		{
			if (ImGui::Button("Arrest", { -FLT_MIN, 0 }))
				plrChr->SetArrested();
		}
	}
}


void DPLMenu::DrawVehicleTab()
{
	ImGui::TextWrapped("Vehicle");
	ImGui::PushItemWidth(-FLT_MIN);
	if (ImGui::BeginCombo("##vehlist", vehicle))
	{
		for (int n = 0; n < IM_ARRAYSIZE(szVehicles); n++)
		{
			bool is_selected = (vehicle == szVehicles[n]);
			if (ImGui::Selectable(szVehicles[n], is_selected))
				sprintf(vehicle, szVehicles[n]);
			if (is_selected)
				ImGui::SetItemDefaultFocus();

		}
		ImGui::EndCombo();
	}

	ImGui::PopItemWidth();

	static Vector carPos = { 0, 0, 0 };

	if (ImGui::CollapsingHeader("Advanced"))
	{
		ImGui::Checkbox("Force Enter Nearest Spawned Car", &m_bForceEnterVehicle);
		ImGui::Checkbox("Set Spawn Color", &m_bSetVehicleColor);
		if (m_bSetVehicleColor)
		{
			ImGui::ColorEdit3("Color", (float*)&m_vVehicleColor);
		}
		ImGui::Checkbox("Set Spawn Position", &m_bSetVehiclePosition);
		if (m_bSetVehiclePosition)
		{
			ImGui::InputFloat3("Position", &carPos.X);
		}

	}
	if (ImGui::Button("Create", { -FLT_MIN, 0 }))
	{
		CCharacter* plrChr = GetLifeSystem()->GetPlayer()->GetDriverBehaviour()->GetCharacter();

		if (!plrChr)
			return;

		if (!m_bSetVehiclePosition)
		{
			Vector4 plrPos;
			plrChr->GetPosition(&plrPos);
			Matrix* plrMat = plrChr->GetMatrix();
			carPos = { plrPos.X, plrPos.Y, plrPos.Z };
			carPos += plrMat->forward * 5.5f;
		}


		CreateVehicle(GetUIDFromName(vehicle), &carPos);
	}


}

void DPLMenu::DrawCameraTab()
{
	GameCamera* cam = GameCamera::GetInstance();

	if (!cam)
		return;
	ImGui::Checkbox("Set Camera Position", &m_bCustomCameraPos);
	ImGui::InputFloat3("X | Y | Z", &m_mCameraMatrix.pos.X);
	ImGui::Checkbox("Set Camera Rotation", &m_bCustomCameraRot);
	ImGui::InputFloat3("Pitch | Yaw | Roll", &m_vecCamRotation.X);
	ImGui::Checkbox("Set FOV", &m_bCustomCameraFOV);
	ImGui::InputFloat("FOV", &m_fCamFOV);

	ImGui::Separator();
	ImGui::Checkbox("Free Camera", &m_bFreeCam);
	if (m_bFreeCam)
	{
		if (!m_bCustomCameraPos || !m_bCustomCameraRot || !m_bCustomCameraFOV)
			ImGui::TextColored(ImVec4(1.f, 0.3f, 0.3f, 1.f), "Check rest of the Set Camera options!");

		{
			ImGui::InputFloat("Free Camera Speed", &m_fFreeCamSpeed);
			ImGui::InputFloat("Free Camera Rotation Speed", &m_fFreeCamRotationSpeed);
		}
	}
	ImGui::Separator();
	if (ImGui::Button("Teleport Player To Camera", { -FLT_MIN, 0 }))
	{
		TeleportPlayer((Vector*)&GameCamera::GetInstance()->camMatrix.pos);
	}
}

void DPLMenu::DrawSpeedTab()
{
	ImGui::Text("Gamespeed Control");
	ImGui::InputFloat("##sms", &m_fSlowMotionSpeed, 0.1f);
	if (m_fSlowMotionSpeed < 0)
		m_fSlowMotionSpeed = 0.0f;

	if (ImGui::Checkbox("Enable", &m_bSlowMotion))
		OnActivateSlowMotion();
}

void DPLMenu::DrawTeleporterTab()
{
	static int nCurOption = 0;

	ImGui::PushItemWidth(-FLT_MIN);
	if (ImGui::BeginCombo("##tplist", teleportName))
	{
		for (int n = 0; n < vTeleports.size(); n++)
		{
			bool is_selected = (teleportName == vTeleports[n].name);
			if (ImGui::Selectable(vTeleports[n].name, is_selected))
			{
				sprintf(teleportName, vTeleports[n].name);
				nCurOption = n;
			}

			if (is_selected)
				ImGui::SetItemDefaultFocus();

		}
		ImGui::EndCombo();
	}
	ImGui::PopItemWidth();


	if (ImGui::Button("Teleport", { -FLT_MIN, 0 }))
	{
		CCharacter* plrChr = GetLifeSystem()->GetPlayer()->GetDriverBehaviour()->GetCharacter();

		if (plrChr)
		{
			if (plrChr->GetVehicle())
			{
				Notifications->SetNotificationTime(2500);
				Notifications->PushNotification("Leave the vehicle first!");
			}
			else
			{
				Notifications->SetNotificationTime(2500);
				Notifications->PushNotification("Teleported to %s", teleportName);
				TeleportPlayer(&vTeleports[nCurOption].pos);
			}

		}


	}

	if (ImGui::CollapsingHeader("Add Location"))
	{
		static Vector newPos = {};

		ImGui::InputFloat3("Position", &newPos.X);
		if (ImGui::Button("Get Player Position"))
		{
			CCharacter* plrChr = GetLifeSystem()->GetPlayer()->GetDriverBehaviour()->GetCharacter();

			if (plrChr)
			{
				Vector4 plrPos;
				plrChr->GetPosition(&plrPos);

				newPos = { plrPos.X, plrPos.Y, plrPos.Z };
			}


		}

		static char newName[260] = {};
		ImGui::InputText("Name", newName, sizeof(newName));

		if (strlen(newName) > 0)
		{
			if (ImGui::Button("Add", { -FLT_MIN, 0 }))
			{
				TeleporterPlace place;
				place.pos = newPos;
				sprintf(place.name, newName);
				vTeleports.push_back(place);
				char str[128] = {};
				sprintf(str, "Place%d", vTeleports.size() - 1);

				locIni->WriteBoolean(str, "is_set", true);
				locIni->WriteString(str, "name", place.name);
				locIni->WriteFloat(str, "x", place.pos.X);
				locIni->WriteFloat(str, "y", place.pos.Y);
				locIni->WriteFloat(str, "z", place.pos.Z);
				Notifications->SetNotificationTime(2500);
				Notifications->PushNotification("Added & saved %s", place.name);

				newPos.X = 0;
				newPos.Y = 0;
				newPos.Z = 0;
				newName[0] = 0x00;
			}
		}
	}
}

void DPLMenu::DrawWorldTab()
{
	if (!GetCCM())
		return;

	if (!GetEnvironment())
		return;

	static float newTime = 0.0f;
	static int  newHour = 0;

	ImGui::TextWrapped("Time (Hour)");
	ImGui::PushItemWidth(-FLT_MIN);
	ImGui::SliderInt("##nh", &newHour, 0, 23);
	ImGui::PopItemWidth();

	if (ImGui::Button("Get Current Time", { -FLT_MIN, 0 }))
	{
		float& timeHour = *(float*)((int)GetEnvironment() + 272);
		newHour = (int)(timeHour / 3600.0f);
	}

	if (ImGui::Button("Set New Time", { -FLT_MIN, 0 }))
	{
		float& timeHour = *(float*)((int)GetEnvironment() + 272);
		timeHour = newHour * 3600.0f;
	}

	ImGui::TextWrapped("Timestep");
	ImGui::PushItemWidth(-FLT_MIN);
	float& timeStep = *(float*)((int)GetEnvironment() + 280);
	ImGui::InputFloat("##ts", &timeStep);
	ImGui::PopItemWidth();

}

void DPLMenu::DrawCheatsTab()
{
	ImGui::Text("Player");
	ImGui::Separator();
	if (ImGui::Checkbox("Invincibility", &m_bInvincibility))
		OnToggleInvincibility();
	ImGui::Separator();
	ImGui::Text("Vehicle");
	ImGui::Separator();
	if (ImGui::Checkbox("Vehicle Invincibility", &m_bInvicibilityCars))
		OnToggleInvincibilityCars();
	if (ImGui::Checkbox("Infinite Nitro", &m_bInfiniteNitro))
		OnToggleInfiniteNitro();
	ImGui::Separator();
	ImGui::Text("Weapons");
	ImGui::Separator();
	ImGui::Checkbox("Rapid Fire", &m_bRapidWeaponFire);
	ImGui::SameLine(); ShowHelpMarker("For best results use everything is autofire and infinite ammo cheats!");
	ImGui::Checkbox("Infinite Ammo", &m_bInfiniteAmmo);
	ImGui::Checkbox("Everything Is Autofire", &m_bEverythingIsAutofire);
	ImGui::Separator();
	ImGui::Text("Felony");
	ImGui::Separator();
	ImGui::Checkbox("Max Felony", &m_bMaxFelony);
	ImGui::Checkbox("Zero Felony", &m_bZeroFelony);
	ImGui::Checkbox("Max Car Felony", &m_bMaxCarFelony);
	ImGui::Checkbox("Zero Car Felony", &m_bZeroCarFelony);
	ImGui::Separator();
	ImGui::Text("Misc.");
	ImGui::Separator();
	ImGui::Checkbox("Infinite Money", &m_bInfiniteMoney);
	ImGui::Separator();
}

void DPLMenu::DrawMiscTab()
{
	ImGui::Checkbox("Disable HUD", &m_bDisableHUD);
}

void DPLMenu::DrawWeaponEditTab()
{
	if (!GetPlayerWeapon())
	{
		ImGui::Text("Equip a weapon first!");
		return;
	}

	CWeapon* w = GetPlayerWeapon();

	ImGui::InputInt("Type", &w->pData->WeaponType);
	ImGui::InputInt("Model ID", &w->pData->ModelID);
	ImGui::InputInt("Ammo Size 1", &w->pData->AmmoSize[0]);
	ImGui::InputInt("Ammo Size 2", &w->pData->AmmoSize[1]);
	ImGui::InputInt("Max Ammo", &w->pData->MaxAmmo);
	ImGui::InputFloat("Range", &w->pData->Range);
	ImGui::InputFloat("Rate Of Fire", &w->pData->RateOfFire);
	ImGui::InputFloat("Spread", &w->pData->Spread);
	ImGui::Checkbox("Automatic", &w->pData->Automatic);
	




}

void DPLMenu::DrawSettings()
{
	ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, { 0.5f, 0.5f });
	ImGui::SetNextWindowPos({ ImGui::GetIO().DisplaySize.x / 2.0f, ImGui::GetIO().DisplaySize.y / 2.0f }, ImGuiCond_Once, { 0.5f, 0.5f });
	ImGui::SetNextWindowSize({ 700,700 }, ImGuiCond_Once);
	ImGui::Begin("Settings", &m_bSubmenuActive[SM_Settings]);

	static int settingID = 0;
	static const char* settingNames[] = {
		"Menu",
		"INI",
		"Keys",
	};

	enum eSettings {
		MENU,
		INI,
		KEYS,
	};

	ImGui::BeginChild("##settings", { 12 * ImGui::GetFontSize(), 0 }, true);

	for (int n = 0; n < IM_ARRAYSIZE(settingNames); n++)
	{
		bool is_selected = (settingID == n);
		if (ImGui::Selectable(settingNames[n], is_selected))
			settingID = n;
		if (is_selected)
			ImGui::SetItemDefaultFocus();
	}

	ImGui::EndChild();

	ImGui::SameLine();
	ImGui::BeginChild("##content", { 0, -ImGui::GetFrameHeightWithSpacing() });

	switch (settingID)
	{
	case MENU:
		ImGui::TextWrapped("All user settings are saved to dplhook_user.ini.");
		ImGui::Text("Menu Scale");
		ImGui::PushItemWidth(-FLT_MIN);
		ImGui::InputFloat("##scale", &SettingsMgr->fMenuScale);
		ImGui::PopItemWidth();
		break;
	case INI:
		ImGui::TextWrapped("These settings control DPLHook.ini options. Any changes require game restart to take effect.");
		ImGui::LabelText("", "Core");
		ImGui::Separator();
		ImGui::Checkbox("Debug Console", &SettingsMgr->bEnableConsoleWindow);
		ImGui::Separator();

		break;
	case KEYS:
		if (m_bPressingKey)
			ImGui::TextColored(ImVec4(0.f, 1.f, 0.3f, 1.f), "Press a key!");

		if (ImGui::Button("Reset Keys", { -FLT_MIN, 0 }))
		{
			SettingsMgr->ResetKeys();
			Notifications->SetNotificationTime(2500);
			Notifications->PushNotification("Keys reset! Remember to save.");
		}

		ImGui::Separator();
		ImGui::LabelText("", "Core");
		ImGui::Separator();
		KeyBind(&SettingsMgr->iMenuOpenKey, "Open/Close Menu", "menu");
		KeyBind(&SettingsMgr->iToggleSlowMoKey, "Toggle Slowmotion", "slomo");
		KeyBind(&SettingsMgr->iToggleHUDKey, "Toggle HUD", "hud");
		KeyBind(&SettingsMgr->iPlayLastAnimationKey, "Play Last Animation", "pla");
		KeyBind(&SettingsMgr->iStopLastAnimationKey, "Stop Last Animation", "sla");
		ImGui::Separator();
		ImGui::LabelText("", "Camera/Airbreak");
		ImGui::Separator();

		KeyBind(&SettingsMgr->iFreeCameraKeyFOVPlus, "FOV+", "fov_plus");
		KeyBind(&SettingsMgr->iFreeCameraKeyFOVMinus, "FOV-", "fov_minus");

		KeyBind(&SettingsMgr->iFreeCameraKeyYawPlus, "Yaw+", "ya_plus");
		KeyBind(&SettingsMgr->iFreeCameraKeyYawMinus, "Yaw-", "ya_minus");
		KeyBind(&SettingsMgr->iFreeCameraKeyPitchPlus, "Pitch+", "pi_plus");
		KeyBind(&SettingsMgr->iFreeCameraKeyPitchMinus, "Pitch-", "pi_minus");
		KeyBind(&SettingsMgr->iFreeCameraKeyRollPlus, "Roll+", "r_plus");
		KeyBind(&SettingsMgr->iFreeCameraKeyRollMinus, "Roll-", "r_minus");

		KeyBind(&SettingsMgr->iFreeCameraKeyForward, "Forward", "x_plus");
		KeyBind(&SettingsMgr->iFreeCameraKeyBack, "Back", "x_minus");
		KeyBind(&SettingsMgr->iFreeCameraKeyLeft, "Left", "y_plus");
		KeyBind(&SettingsMgr->iFreeCameraKeyRight, "Right", "y_minus");
		KeyBind(&SettingsMgr->iFreeCameraKeyUp, "Up", "z_plus");
		KeyBind(&SettingsMgr->iFreeCameraKeyDown, "Down", "z_minus");
		ImGui::Separator();

		if (m_bPressingKey)
		{
			eVKKeyCode result = eKeyboardMan::GetLastKey();

			if (result >= VK_BACKSPACE && result < VK_KEY_NONE)
			{
				*m_pCurrentVarToChange = result;
				m_bPressingKey = false;
			}

		}
		break;
	default:
		break;
	}

	if (ImGui::Button("Save", { -FLT_MIN, 0 }))
	{
		Notifications->SetNotificationTime(2500);
		Notifications->PushNotification("Settings saved to DPLHook.ini and dplhook_user.ini!");
		eDirectX9Hook::ms_bShouldReloadFonts = true;
		SettingsMgr->SaveSettings();
	}

	ImGui::EndChild();
	ImGui::PopStyleVar();

	ImGui::End();
}

void DPLMenu::DrawKeyBind(char* name, int* var)
{
	ImGui::SameLine();

	static char butName[256] = {};
	sprintf(butName, "%s##key%s", eKeyboardMan::KeyToString(*var), name);
	if (ImGui::Button(butName))
	{
		m_bPressingKey = true;
		m_pCurrentVarToChange = var;
	}
}

void DPLMenu::KeyBind(int* var, char* bindName, char* name)
{
	ImGui::LabelText("", bindName);
	DrawKeyBind(name, var);
}

void DPLMenu::LoadLocationFile()
{
	static CIniReader locations("dplhook_locations.ini");
	locIni = &locations;

	for (int i = 0; i < MAX_TELEPORTS; i++)
	{
		char str[128] = {};
		sprintf(str, "Place%d", i);

		bool is_set = locations.ReadBoolean(str, "is_set", false);
		if (is_set)
		{
			TeleporterPlace place;
			Vector tpPos = {};
			tpPos.X = locations.ReadFloat(str, "x", 0.0f);
			tpPos.Y = locations.ReadFloat(str, "y", 0.0f);
			tpPos.Z = locations.ReadFloat(str, "z", 0.0f);

			place.pos = tpPos;
			sprintf(place.name, "%s", locations.ReadString(str, "name", str));
			vTeleports.push_back(place);
		}
	}
}

tVehicleModelUID GetUIDFromName(const char* name)
{
	int id = 0;
	for (int i = 0; i < sizeof(szVehicles) / sizeof(szVehicles[0]); i++)
	{
		if (strcmp(szVehicles[i], name) == 0)
		{
			id = i;
			break;
		}
	}
	return (tVehicleModelUID)id;
}

EWeapons GetWIDFromName(const char* name)
{
	int id = 0;
	for (int i = 0; i < sizeof(szWeapons) / sizeof(szWeapons[0]); i++)
	{
		if (strcmp(szWeapons[i], name) == 0)
		{
			id = i;
			break;
		}
	}
	return (EWeapons)id;
}

void Plugin_UpdateThread()
{
	while (true)
	{
		// disable input while menu or airbreak is active, mouse is disabled via dinput8 hook
		Patch<char>(0x574A24, (TheMenu->m_bIsActive || TheMenu->m_bAirbreak) ? 0xC3 : 0x55);
		TheMenu->Update();
		TheMenu->UpdateColors();
		Notifications->Update();
		Sleep(1);
	}


}

float GetDeltaTime()
{
	float delta = 1.0f / 60.0f;

	if (eDirectX9Hook::ms_bInit)
		delta = 1.0f / ImGui::GetIO().Framerate;

	return delta;
}