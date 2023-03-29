#include "AnimLib.h"

CJointState::CJointState()
{
	((void(__thiscall*)(CJointState*))0x5C35D8)(this);
}

void CJointState::GetMatrix(Matrix* m)
{
	((void(__thiscall*)(CJointState*, Matrix*))0x5C3AD2)(this, m);
}

CAnimClip* CAnimClipIndex::GetClip()
{
	return 	((CAnimClip*(__thiscall*)(CAnimClipIndex*))0x5C3CFD)(this);
}

CAnimJoint* CAnimClip::GetJoint(int BoneID)
{
	return 	((CAnimJoint*(__thiscall*)(CAnimClip*, int))0x5C3E7B)(this, BoneID);
}

void CAnimJoint::GetState(CJointState* state, float time)
{
	((void(__thiscall*)(CAnimJoint*, CJointState*, float))0x5C3AD2)(this, state, time);
}

unsigned int HashAnimName(const char* name)
{
	unsigned int hash = 0;
	int counter = 0;
	while (*name)
		*((unsigned char*)&hash + (counter++ & 3)) += *name++;
	return 	hash;
}
