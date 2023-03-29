#pragma once
#include "VehicleModel.h"
#include "Vector4.h"
#include "Vehicle.h"

class CLifeSystem_SoftSaveVehicle {
public:
	char pad[28];
	CVehicle** pSavedVehicle;
};

class CLifeInstances {
public:
	CLifeSystem_SoftSaveVehicle* GetSSV();
	void CreateVehicle(CVehicle* pVehicle, tVehicleModelUID tVehicle, Vector4* vPosition, float fRotation);

};


CLifeInstances* GetLifeInstances();