#pragma once
#include "CharacterWeapons.h"
#include "Character.h"
#include "..\core\Matrix.h"

class CPlayerDriverBehaviour {
public:
	CCharacterWeapons* GetWeapons();

	CCharacter* GetCharacter();
	bool HasShotRecently();
	void AddAllWeapons();
	bool IsFreeAiming();
	void PlayerIsStuck();
};