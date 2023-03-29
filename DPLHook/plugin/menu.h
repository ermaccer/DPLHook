#pragma once
#include "..\dpl\VehicleModel.h"
#include "..\dpl\Weapons.h"
#include "..\dpl\Vehicle.h"
#include "..\imgui\imgui.h"
#include "..\core\Matrix.h"
#include "..\core\Vector.h"

#include "..\IniReader.h"
#include <DirectXMath.h>
using namespace DirectX;

#define MAX_TELEPORTS 200
#define NUM_ANIMS 1358
#define DPLHOOK_VERSION "0.1"

enum eMenuSubMenus {
	SM_Settings,
	SM_Total
};

struct TeleporterPlace {
	Vector pos;
	char   name[260] = {};
};


extern const char* szAnimations[NUM_ANIMS];


class DPLMenu {
public:
	bool	 m_bIsActive = false;
	bool	 m_bSubmenuActive[SM_Total] = {};
	bool     m_bPressingKey = false;
	bool	 m_bSlowMotion = false;
	bool	 m_bIsFocused = true;
	bool	 m_bAirbreak = false;

	bool	 m_bCustomCameraPos = false;
	bool	 m_bCustomCameraRot = false;
	bool	 m_bCustomCameraFOV = false;
	bool	 m_bFreeCam = false;
	bool	 m_bDisableHUD = false;

	bool     m_bForceEnterVehicle = false;
	bool	 m_bSetVehicleColor = false;
	bool	 m_bSetVehiclePosition = false;


	// cheats
	bool	m_bRapidWeaponFire = false;
	bool    m_bInfiniteAmmo = false;
	bool    m_bEverythingIsAutofire = false;
	bool	m_bInfiniteMoney = false;
	bool    m_bInvincibility = false;
	bool	m_bInvicibilityCars = false;
	bool    m_bInfiniteNitro = false;
	bool	m_bMaxCarFelony = false;
	bool	m_bZeroCarFelony = false;
	bool	m_bMaxFelony = false;
	bool	m_bZeroFelony = false;

	int	     m_nBoneID = 0;
	int      m_nMatID = 0;
	int      m_nLastEra = -1;
	int      m_nCurrentEra = 0;


	float	 m_fSlowMotionSpeed = 0.5f;
	float	 m_fFreeCamSpeed = 5.25f;
	float	 m_fAirbreakSpeed = 20.25f;
	float    m_fFreeCamRotationSpeed = 2.25f;
	float	 m_fCamFOV = 0.0f;
	float    m_fYOffset = 0.0f;

	ImVec4	 m_vVehicleColor = {1.0f, 1.0f, 1.0f, 1.0f};

	Matrix   m_mCameraMatrix = {};
	Vector   m_vecCamRotation = {};
	Vector   m_vecPlrPosition;


	int* m_pCurrentVarToChange = nullptr;

	CIniReader* locIni;

	char	 vehicle[256] = {};
	char	 weapon[256] = {};
	char	 teleportName[256] = {};
	char     animation[256] = {};
	char	 character[256] = {};

	DPLMenu();

	void	 OnActivate();
	void     OnActivateSlowMotion();
	void	 OnActivatePlayLastAnim();
	void	 OnActivateStopLastAnim();
	void	 OnToggleSlowMotion();
	void	 OnToggleHUD();

	void	 OnToggleInvincibility();
	void	 OnToggleInvincibilityCars();
	void	 OnToggleInfiniteNitro();

	void	 Draw();
	void	 Update();
	void	 UpdateKeys();
	void	 UpdateFreeCamera();
	void	 UpdateAirBreak();
	void     UpdateColors();
	void	 UpdateCheats();

	void     DrawPlayerTab();
	void	 DrawVehicleTab();
	void     DrawCameraTab();
	void     DrawSpeedTab();
	void 	 DrawTeleporterTab();
	void	 DrawWorldTab();
	void     DrawCheatsTab();
	void	 DrawMiscTab();
	void     DrawWeaponEditTab();


	void	 DrawSettings();


	void	 DrawKeyBind(char* name, int* var);
	void	 KeyBind(int* var, char* bindName, char* name);

	void     LoadLocationFile();
};

tVehicleModelUID GetUIDFromName(const char* name);
EWeapons		 GetWIDFromName(const char* name);
extern DPLMenu* TheMenu;

void Plugin_UpdateThread();
float GetDeltaTime();
