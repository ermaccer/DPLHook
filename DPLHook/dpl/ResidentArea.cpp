#include "ResidentArea.h"

ResidentAreaClass* GetResidentArea()
{
    return ((ResidentAreaClass*(__cdecl*)())0x525A90)();
}

void ResidentAreaClass::AddResidentAreaDependant(int unk, int unk2, CVehicleManager* vm, float* r)
{
    ((void(__thiscall*)(ResidentAreaClass*, int, int, CVehicleManager*, float*))0x525BC0)(this, unk, unk2, vm, r);
}
