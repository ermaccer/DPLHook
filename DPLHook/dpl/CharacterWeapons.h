#pragma once
#include "Weapons.h"
#include "Weapon.h"

class CCharacterWeapons {
public:
	void AddWeapon(EWeapons eWeapon, int nAmmo, int unk);
	void ClearAllWeapons();
	void FindSpecificWeapon(CWeapon* pWeapon, EWeapons eWeapon);
	void SelectWeapon();
	void ForceSelectWeapon(EWeapons eWeapon);
};