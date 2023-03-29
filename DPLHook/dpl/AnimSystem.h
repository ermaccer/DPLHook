#pragma once
#include "AnimInstance.h"

enum EBoneIDs {
	bone_pelvis,
	bone_left_upperleg,
	bone_left_lowerleg,
	bone_left_foot,
	bone_right_upperleg,
	bone_right_lowerleg,
	bone_right_foot,
	bone_left_clavicle,
	bone_left_upperarm,
	bone_left_lowerarm,
	bone_left_wrist,
	bone_left_hand,
	bone_left_fingers,
	bone_right_clavicle,
	bone_right_upperarm,
	bone_right_lowerarm,
	bone_right_wrist,
	bone_right_hand,
	bone_gun,
	bone_head,
	bone_hair,
	bone_21,
	bone_root
};

class HAnimSystem {
public:
	HAnimClip* GetClip(HAnimClip* clip, int ID);
};

HAnimSystem* GetAnimSystem();

class CAnimIndexManager {
public:
	HAnimClip* GetClipIndexEntry(int* id);
};
CAnimIndexManager* GetAnimManager();