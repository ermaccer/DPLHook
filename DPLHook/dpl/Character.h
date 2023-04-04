#pragma once
#include "..\core\Vector.h"
#include "Vector4.h"
#include "Vehicle.h"
#include "..\core\Matrix.h"
#include "AnimInstance.h"
#include "Weapon.h"
#include "ECharAnimType.h"

class CVehicle;

class CCharacterRendering {
public:

};

class CCharacter {
public:


	void GetPosition(Vector4* pos);
	void Crouch(bool a1, bool a2);
	void SetArrested();
	void ForceIdleMode();
	void PlayMissionAnimation(unsigned int animHash, bool unk);
	void KillMissionAnimations();
	void EnterVehicle(CVehicle* pVehicle, int nDoor, bool unk1, bool unk2);
	void ExitVehicle(int Reason);
	void EnterVehicleImmediate(CVehicle* pVehicle, int nDoor, bool unk1);
	void GetAnimationRootMatrix(Matrix* m, HAnimClip* clip, float time);
	bool ValidWeapon();

	void SetPosition(Vector4* pos);
	void SetModel(int model);
	void SetAnimType(int type);

	int* GetAnimTypePointer();

	void DrawCrosshair(int Viewport, int unk);
	void DrawCrosshairHook(int Viewport, int unk);

	CCharacterRendering* GetRendering();
	CVehicle* GetVehicle();
	Matrix* GetMatrix();
	HAnimInstance* GetAnimInstance();
	CWeapon* GetWeapon();

	bool IsWeaponDrawn();
	bool IsWeaponRequested();
};