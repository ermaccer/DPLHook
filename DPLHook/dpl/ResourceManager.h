#pragma once

class SpoolableResourceManager {
public:
	void SetEntityPriority(int Package, int ID, int unk);
	void RequestEntity(int Package, int ID, int unk, int unk2);
	bool IsEntityLoaded(int Package, int ID);
	bool IsEntityPresent(int Package, int ID);
};

SpoolableResourceManager* GetResourceManager();