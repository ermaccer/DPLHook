#include "LifeEnvironment.h"

void CLifeEnvironment::SetLifeTime(float NewTime)
{
    ((void(__thiscall*)(CLifeEnvironment*, float))0x46C327)(this, NewTime);
}

CLifeEnvironment* GetEnvironment()
{
    return *(CLifeEnvironment**)0x70C7E0;
}
