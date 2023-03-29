#include "CharacterCategoryManager.h"

CCharacterCategoryManager* GetCCM()
{
    return *(CCharacterCategoryManager**)0x70C6E4;
}

void CCharacterCategoryManager::SetEra(ECCMEra Era)
{
    ((void(__thiscall*)(CCharacterCategoryManager*, ECCMEra))0x4F3454)(this, Era);
}

ECCMEra CCharacterCategoryManager::GetEra()
{
    return ((ECCMEra(__thiscall*)(CCharacterCategoryManager*))0x4F2E9A)(this);
}

void CCharacterCategoryManager::SetPlayerAvatar(int ID)
{
    ((void(__thiscall*)(CCharacterCategoryManager*,int))0x4F31F5)(this, ID);
}
