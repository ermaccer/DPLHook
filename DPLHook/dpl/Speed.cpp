#include "Speed.h"

void speed::SetMasterSpeedMultiplier(float NewSpeed)
{
	*(float*)(0x684124) = NewSpeed;
	((void(__thiscall*)(int, float))0x45A7EB)(*(int*)0x70C768 + 296, NewSpeed * 120.0f);
}
