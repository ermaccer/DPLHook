#pragma once
#include "..\core\Vector.h"
#include "VehicleModel.h"
#include "VehicleManager.h"
#include "VehicleSpecification.h"
#include "Weapons.h"
#include "Weapon.h"
#include "LifeSystem.h"

void CreateVehicle(tVehicleModelUID id, Vector* pos);
void GiveWeaponToPlayer(EWeapons eWeapon);
void TeleportPlayer(Vector* pos);
CWeapon* GetPlayerWeapon();
void SetPlayerModel(int model);