#include "ResourceManager.h"

void SpoolableResourceManager::SetEntityPriority(int Package, int ID, int unk)
{
	((void(__thiscall*)(SpoolableResourceManager*, int, int, int))0x5492B8)(this, Package, ID, unk);
}

void SpoolableResourceManager::RequestEntity(int Package, int ID, int unk, int unk2)
{
	((void(__thiscall*)(SpoolableResourceManager*, int, int, int))0x549284)(this, Package, ID, unk);
}

bool SpoolableResourceManager::IsEntityLoaded(int Package, int ID)
{
	return ((bool(__thiscall*)(SpoolableResourceManager*, int, int))0x5481F7)(this, Package, ID);
}

bool SpoolableResourceManager::IsEntityPresent(int Package, int ID)
{
	return ((bool(__thiscall*)(SpoolableResourceManager*, int, int))0x547F5E)(this, Package, ID);
}

SpoolableResourceManager* GetResourceManager()
{
	return *(SpoolableResourceManager**)(0x70C64C);
}
