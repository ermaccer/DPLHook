#include "LifeSystem.h"

CLifePlayer* CLifeSystem::GetPlayer()
{
    return pPlayer;
}

void CLifeSystem::GetPingRadii(float* r)
{
    ((void(__thiscall*)(CLifeSystem*, float*))0x4719B5)(this, r);
}

CLifeSystem* GetLifeSystem()
{
    return *(CLifeSystem**)0x70C7C4;
}
