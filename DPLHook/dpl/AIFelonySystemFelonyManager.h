#pragma once
#include "Character.h"
#include "Vehicle.h"
#include "Vector4.h"

class CVehicle;
class CCharacter;

class AIFelonySystemFelonyManagerClass {
public:
	void SetVehicleFelonyLevel(CVehicle* pVehicle, int CarType, float Value);
	void SetFelonyLevel(CCharacter* pCharacter, int CarType, float Value);
	void CreatePatrolHelicopterUnit(Vector4* Position, int CarType, float Value);
};

AIFelonySystemFelonyManagerClass* GetFelonyManager();