#pragma once

enum ECCMEra {
	CCM_Era_Then,
	CCM_Era_Now
};

class CCharacterCategoryManager {
public:
	void SetEra(ECCMEra Era);
	ECCMEra GetEra();

	void SetPlayerAvatar(int ID);
};

CCharacterCategoryManager* GetCCM();