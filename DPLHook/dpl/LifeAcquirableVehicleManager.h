#pragma once
#include "Vehicle.h"
class LifeAcquirableVehicleManagerClass {
public:
	void AddVehicle(CVehicle* pVehicle, int a2);
	int  NumberOfVehicles();
};

LifeAcquirableVehicleManagerClass* GetLifeAcquirableVehicleManager();