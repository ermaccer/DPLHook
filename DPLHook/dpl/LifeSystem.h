#pragma once
#include "Player.h"

class CLifeSystem {
public:
	int field0;
	int field4;
	CLifePlayer* pPlayer;

	CLifePlayer* GetPlayer();
	void GetPingRadii(float* r);
};


CLifeSystem* GetLifeSystem();