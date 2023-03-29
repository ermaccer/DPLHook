#include "LifeProgression.h"

CLifeProgression* GetLifeProgression()
{
    return ((CLifeProgression* (__cdecl*)())0x4700B3)();
}

void CLifeProgression::RunEvent(int EventID)
{
    ((void(__thiscall*)(CLifeProgression*, int))0x47125A)(this, EventID);
}
