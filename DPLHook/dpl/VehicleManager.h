#pragma once
#include "VehicleSpecification.h"
#include "VehicleModel.h"
#include "Vehicle.h"

class CVehicle;

class CVehicleManager {
public:
	CVehicle** CreateVehicle(CVehicle** pVehicle, tVehicleModelUID tVehicle, float x, float y, float z, float w, float fRotation, bool unk1, bool unk2, bool unk3);
};


CVehicleManager* GetVehicleManager();