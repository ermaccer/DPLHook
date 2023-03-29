#pragma once

struct CWeaponData {
	int WeaponType;
	int ModelID;
	int AmmoSize[2];
	int field16;
	int field20;
	float Range;
	float RateOfFire;
	bool  Automatic;
	char  pad[3];
	int   field36;
	float Spread;
	int   MaxAmmo;

};

class CWeapon {
public:
	void* vTable;
	CWeaponData* pData;
	int	  TotalAmmo;
	int   CurrentAmmo;
	int   InfiniteAmmo;
	int   CooldownTimer;
	int   CooldownTimerTwo;


	void Shoot();
	void Reload();

	void Step();
	bool IsAutomatic();
	bool IsAutomaticHook();
};

void RapidFireCheat_Hook();