#include "AIFelonySystemFelonyManager.h"

AIFelonySystemFelonyManagerClass* GetFelonyManager()
{
    return *(AIFelonySystemFelonyManagerClass**)(0x70C5C8);
}

void AIFelonySystemFelonyManagerClass::SetVehicleFelonyLevel(CVehicle* pVehicle, int CarType, float Value)
{
    ((void(__thiscall*)(AIFelonySystemFelonyManagerClass*, CVehicle*, float, int))0x430FF9)(this, pVehicle, Value, CarType);
}

void AIFelonySystemFelonyManagerClass::SetFelonyLevel(CCharacter* pCharacter, int CarType, float Value)
{
    ((void(__thiscall*)(AIFelonySystemFelonyManagerClass*, CCharacter*, float, int))0x430A18)(this, pCharacter, Value, CarType);
}

void AIFelonySystemFelonyManagerClass::CreatePatrolHelicopterUnit(Vector4* Position, int CarType, float Value)
{
    ((void(__thiscall*)(AIFelonySystemFelonyManagerClass*,Vector4*, float, int))0x4299A3)(this, Position, Value, CarType);
}
