#include "LifeAcquirableVehicleManager.h"

void LifeAcquirableVehicleManagerClass::AddVehicle(CVehicle* pVehicle, int a2)
{
	((void(__thiscall*)(LifeAcquirableVehicleManagerClass*, CVehicle*, int))0x4A2D97)(this, pVehicle, a2);
}

int LifeAcquirableVehicleManagerClass::NumberOfVehicles()
{
	return *(int*)(this + 0x20C);
}

LifeAcquirableVehicleManagerClass* GetLifeAcquirableVehicleManager()
{
	return  ((LifeAcquirableVehicleManagerClass*(__cdecl*)())0x4A2CA1)();
}
