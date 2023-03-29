#pragma once
#include "PlayerDriverBehaviour.h"

class CLifePlayer {
public:
	int field0;
	int field4;
	CPlayerDriverBehaviour* pDriverBehaviour;

	CPlayerDriverBehaviour* GetDriverBehaviour();

};