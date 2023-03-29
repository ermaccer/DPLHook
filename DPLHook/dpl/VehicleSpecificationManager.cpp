#include "VehicleSpecificationManager.h"

CVehicleSpecificationManager_Proper* pVehicleSpecificationManager;


void CVehicleSpecificationManager_Proper::GetVehicleSpecification(CVehicleSpecification* pSpecficiation, tVehicleModelUID tVehicle)
{
	((void(__thiscall*)(CVehicleSpecificationManager_Proper*, CVehicleSpecification*, tVehicleModelUID))0x580290)(this, pSpecficiation, tVehicle);
}

bool CVehicleSpecificationManager_Proper::IsVehicleLoaded(tVehicleModelUID tVehicle)
{
	return 	((bool(__thiscall*)(CVehicleSpecificationManager_Proper*, tVehicleModelUID))0x580197)(this, tVehicle);
}

CVehicleSpecificationManager_Proper* GetVehicleSpecificationManager()
{
	return *(CVehicleSpecificationManager_Proper**)(0x70C824);
}

void* CVehicleSpecificationManager_Proper_Hook_Constructor(int nSize)
{
	void* result = ((void*(__cdecl*)(int))0x4014C2)(nSize);
	pVehicleSpecificationManager = (CVehicleSpecificationManager_Proper*)result;
	return result;
}
