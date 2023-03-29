#include "VehicleManager.h"
#include <iostream>

CVehicleManager* GetVehicleManager()
{
    return (CVehicleManager*)(*(int*)(0x70C830) - 4);
}

CVehicle** CVehicleManager::CreateVehicle(CVehicle** pVehicle, tVehicleModelUID tVehicle, float x, float y, float z, float w, float fRotation, bool unk1, bool unk2, bool unk3)
{
    return ((CVehicle** (__thiscall*)(CVehicleManager*, CVehicle**, tVehicleModelUID, float, float, float, float, float, bool, bool, bool))0x5B154B)(this, pVehicle, tVehicle, x, y, z, w, fRotation, unk1, unk2, unk3);
}
