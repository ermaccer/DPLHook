#pragma once
#include "VehicleManager.h"
#include "LifeInstances.h"

class ResidentAreaClass {
public:
	void AddResidentAreaDependant(int unk, int unk2, CVehicleManager* vm, float* r);
};

ResidentAreaClass* GetResidentArea();