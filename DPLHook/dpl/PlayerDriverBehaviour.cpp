#include "PlayerDriverBehaviour.h"

CCharacterWeapons* CPlayerDriverBehaviour::GetWeapons()
{
    return (CCharacterWeapons*)((int)this + 0x20C);
}

CCharacter* CPlayerDriverBehaviour::GetCharacter()
{
    return *(CCharacter**)((int)this + 0x2C4);
}

bool CPlayerDriverBehaviour::HasShotRecently()
{
    return ((bool(__thiscall*)(CPlayerDriverBehaviour*))0x4A2AD6)(this);
}

void CPlayerDriverBehaviour::AddAllWeapons()
{
    ((void(__thiscall*)(CPlayerDriverBehaviour*))0x49F419)(this);
}

bool CPlayerDriverBehaviour::IsFreeAiming()
{
    return ((bool(__thiscall*)(CPlayerDriverBehaviour*))0x4A2B57)(this);
}

void CPlayerDriverBehaviour::PlayerIsStuck()
{
    ((void(__thiscall*)(CPlayerDriverBehaviour*))0x4A2B2C)(this);
}
