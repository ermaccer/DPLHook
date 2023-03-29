#pragma once
#include "..\core\Matrix.h"

class CJointState {
public:
	int field0;
	int field4;
	int field8;
	int field12;
	int field16;
	int field20;
	int field24;
	int field28;

	CJointState();
	void GetMatrix(Matrix* m);
};

class CAnimJoint {
public:
	void GetState(CJointState* state, float time);
};

class CAnimClip {
public:
	CAnimJoint* GetJoint(int BoneID);
};

class CAnimClipIndex {
public:
	CAnimClip* GetClip();
};


unsigned int HashAnimName(const char* name);