#pragma once
#include "..\core\Matrix.h"

class HAnimClip {
public:
	char data[64] = {};
	int* GetId(); // actually a hash
	void	   GetJointMatrix(Matrix* mat, int BoneID, float Time);
};

class HAnimInstance {
public:
	HAnimClip* GetClip(HAnimClip* AnimClip, int ID);
	float	   GetClipTime(int ID);
};