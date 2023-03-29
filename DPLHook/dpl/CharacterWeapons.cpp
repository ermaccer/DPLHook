#include "CharacterWeapons.h"

void CCharacterWeapons::AddWeapon(EWeapons eWeapon, int nAmmo, int unk)
{
	((void(__thiscall*)(CCharacterWeapons*, EWeapons, int, int))0x4FB5A0)(this, eWeapon, nAmmo, unk);
}

void CCharacterWeapons::ClearAllWeapons()
{
	((void(__thiscall*)(CCharacterWeapons*))0x4FB55F)(this);
}

void CCharacterWeapons::FindSpecificWeapon(CWeapon* pWeapon, EWeapons eWeapon)
{
	((void(__thiscall*)(CCharacterWeapons*, CWeapon*, EWeapons))0x4FB2EE)(this, pWeapon, eWeapon);
}

void CCharacterWeapons::SelectWeapon()
{
	((void(__thiscall*)(CCharacterWeapons*))0x4FB47A)(this);
}

void CCharacterWeapons::ForceSelectWeapon(EWeapons eWeapon)
{
	*(int*)((int)this + 168) = eWeapon;
	SelectWeapon();
}
