#include "Character.h"
#include "..\plugin\menu.h"

void CCharacter::GetPosition(Vector4* pos)
{
	((void(__thiscall*)(CCharacter*, Vector4*))0x4F2A5E)(this, pos);
}

void CCharacter::Crouch(bool a1, bool a2)
{
	((void(__thiscall*)(CCharacter*, bool, bool))0x4E7ADC)(this, a1, a2);
}

void CCharacter::SetArrested()
{
	((void(__thiscall*)(CCharacter*))0x4F2A32)(this);
}

void CCharacter::ForceIdleMode()
{
	((void(__thiscall*)(CCharacter*))0x4E9E0A)(this);
}

void CCharacter::PlayMissionAnimation(unsigned int animHash, bool unk)
{
	((void(__thiscall*)(CCharacter*, unsigned int, bool))0x4E9E24)(this, animHash, unk);
}

void CCharacter::KillMissionAnimations()
{
	((void(__thiscall*)(CCharacter*))0x4E863F)(this);
}

void CCharacter::EnterVehicle(CVehicle* pVehicle, int nDoor, bool unk1, bool unk2)
{
	((void(__thiscall*)(CCharacter*, CVehicle*, int, bool, bool))0x4EBF46)(this, pVehicle, nDoor, unk1, unk2);
}

void CCharacter::ExitVehicle(int Reason)
{
	((void(__thiscall*)(CCharacter*))0x4E7BB6)(this);
}

void CCharacter::EnterVehicleImmediate(CVehicle* pVehicle, int nDoor, bool unk1)
{
	((void(__thiscall*)(CCharacter*, CVehicle*, int, bool))0x4EB560)(this, pVehicle, nDoor, unk1);
}

void CCharacter::GetAnimationRootMatrix(Matrix* m, HAnimClip* clip, float time)
{
	((void(__thiscall*)(CCharacter*, Matrix*, HAnimClip*, float))0x4E7FC7)(this, m, clip, time);
}

bool CCharacter::ValidWeapon()
{
	return 	((bool(__thiscall*)(CCharacter*))0x4E8163)(this);
}

void CCharacter::SetPosition(Vector4* pos)
{
	GetMatrix()->pos = { pos->X, pos->Y, pos->Z };
}

void CCharacter::SetModel(int model)
{
	*(int*)((int)this + 0x744) = model;
	*(int*)((int)this + 0x764) = model;
}

void CCharacter::SetAnimType(int type)
{
	*(int*)((int)this + 0x63C) = type;
}

int* CCharacter::GetAnimTypePointer()
{
	return (int*)((int)this + 0x63C);
}

void CCharacter::DrawCrosshair(int Viewport, int unk)
{
	((void(__thiscall*)(CCharacter*, int, int))0x4EB954)(this, Viewport, unk);
}

void CCharacter::DrawCrosshairHook(int Viewport, int unk)
{
	if (TheMenu->m_bDisableHUD)
		return;

	DrawCrosshair(Viewport, unk);
}

CCharacterRendering* CCharacter::GetRendering()
{
	return (CCharacterRendering*)((int)this + 1680);
}

CVehicle* CCharacter::GetVehicle()
{
	return *(CVehicle**)((int)this + 0x688);
}

Matrix* CCharacter::GetMatrix()
{
	return (Matrix*)((int)this + 16);
}

HAnimInstance* CCharacter::GetAnimInstance()
{
	return  (HAnimInstance*)((int)this + 0x5FC);
}

CWeapon* CCharacter::GetWeapon()
{
	if (!ValidWeapon())
		return nullptr;
	return (CWeapon*)((int)this + 208);
}

bool CCharacter::IsWeaponDrawn()
{
	return 	((bool(__thiscall*)(CCharacter*))0x4EAD61)(this);
}

bool CCharacter::IsWeaponRequested()
{
	return 	((bool(__thiscall*)(CCharacter*))0x4EADA1)(this);
}
