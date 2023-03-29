#pragma once
#include "Character.h"

class CCharacter;

class CVehicle {
public:
	void SetColor(float R, float G, float B);
	void SetDriver(CCharacter* pDriver, bool unk);
	void RestoreDamage();
	void ResetDamage();
	void MakeInfiniteMass();
	void Explode();
	void Kaboom();

};