#include "AnimSystem.h"

HAnimSystem* GetAnimSystem()
{
    return *(HAnimSystem**)0x70C584;
}

CAnimIndexManager* GetAnimManager()
{
    return *(CAnimIndexManager**)(0x70C580);
}

HAnimClip* HAnimSystem::GetClip(HAnimClip* clip, int ID)
{
    return ((HAnimClip * (__thiscall*)(HAnimSystem*, HAnimClip*, int))0x57445C)(this, clip, ID);
}

HAnimClip* CAnimIndexManager::GetClipIndexEntry(int* id)
{
    return ((HAnimClip * (__thiscall*)(CAnimIndexManager*, int*))0x55F1C5)(this, id);
}
