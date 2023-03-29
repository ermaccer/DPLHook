#include "AnimInstance.h"

HAnimClip* HAnimInstance::GetClip(HAnimClip* AnimClip, int ID)
{
    return 	((HAnimClip*(__thiscall*)(HAnimInstance*, HAnimClip*, int))0x5742B5)(this, AnimClip, ID);
}

float HAnimInstance::GetClipTime(int ID)
{
    return ((float(__thiscall*)(HAnimInstance*, int))0x573E23)(this, ID);
}

int* HAnimClip::GetId()
{
    return 	((int*(__thiscall*)(HAnimClip*))0x573AFC)(this);
}

void HAnimClip::GetJointMatrix(Matrix* mat, int BoneID, float Time)
{
    ((void(__thiscall*)(HAnimClip*, Matrix*, int, float))0x573B84)(this, mat, BoneID, Time);
}
