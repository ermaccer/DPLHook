#include "LifeInstances.h"

CLifeInstances* GetLifeInstances()
{
    return ((CLifeInstances*(__cdecl*)())0x46E91F)();
}

CLifeSystem_SoftSaveVehicle* CLifeInstances::GetSSV()
{
    return (CLifeSystem_SoftSaveVehicle*)((int)this + 0x6C8);
}

void CLifeInstances::CreateVehicle(CVehicle* pVehicle, tVehicleModelUID tVehicle, Vector4* vPosition, float fRotation)
{
   ((void(__thiscall*)(CLifeInstances*, CVehicle*, tVehicleModelUID, Vector4*, float))0x46F230)(this, pVehicle, tVehicle, vPosition, fRotation);
}
