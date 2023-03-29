#pragma once
#include "VehicleSpecification.h"
#include "VehicleModel.h"

class CVehicleSpecificationManager_Proper {
public:
	void	GetVehicleSpecification(CVehicleSpecification* pSpecficiation, tVehicleModelUID tVehicle);
	bool	IsVehicleLoaded(tVehicleModelUID tVehicle);
};


CVehicleSpecificationManager_Proper* GetVehicleSpecificationManager();

extern CVehicleSpecificationManager_Proper* pVehicleSpecificationManager;


void* CVehicleSpecificationManager_Proper_Hook_Constructor(int nSize);
