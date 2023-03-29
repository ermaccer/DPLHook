#include "Vehicle.h"

void CVehicle::SetColor(float R, float G, float B)
{
	*(float*)(this + 140) = R;
	*(float*)(this + 144) = G;
	*(float*)(this + 148) = B;
}

void CVehicle::SetDriver(CCharacter* pDriver, bool unk)
{
	((void(__thiscall*)(CVehicle*, CCharacter*, bool))0x5AF036)(this,pDriver, unk);
}

void CVehicle::RestoreDamage()
{
	((void(__thiscall*)(CVehicle*))0x5AF35E)(this);
}

void CVehicle::ResetDamage()
{
	((void(__thiscall*)(CVehicle*))0x5AD2A8)(this);
}

void CVehicle::MakeInfiniteMass()
{
	((void(__thiscall*)(CVehicle*))0x57F4D6)(this);
}

void CVehicle::Explode()
{
	((void(__thiscall*)(CVehicle*))0x5AB787)(this);
}

void CVehicle::Kaboom()
{
	((void(__thiscall*)(CVehicle*))0x59D417)(this);
}
