#pragma once

enum eCharAnimType
{
	eCharAnimType_None = -1,
	eCharAnimType_GenericAddict = 0,
	eCharAnimType_GenericAsthmatic = 1,
	eCharAnimType_GenericBallsy = 2,
	eCharAnimType_GenericBitch = 3,
	eCharAnimType_GenericBouncer = 4,
	eCharAnimType_GenericCop = 5,
	eCharAnimType_GenericCoward = 6,
	eCharAnimType_GenericFat = 7,
	eCharAnimType_GenericCharacter = 8,
	eCharAnimType_GenericGirlie = 9,
	eCharAnimType_GenericHatted = 10,
	eCharAnimType_GenericLady = 11,
	eCharAnimType_GenericLongHaired = 12,
	eCharAnimType_GenericMilitary = 13,
	eCharAnimType_GenericOriental = 14,
	eCharAnimType_GenericPimp = 15,
	eCharAnimType_GenericSlob = 16,
	eCharAnimType_GenericThug = 17,
	eCharAnimType_GenericHipHop = 18,
	eCharAnimType_TheKid = 19,
	eCharAnimType_Slink = 20,
	eCharAnimType_Corrigan = 21,
	eCharAnimType_Bishop = 22,
	eCharAnimType_Candy = 23,
	eCharAnimType_Ray = 24,
	eCharAnimType_TheMexican = 25,
	eCharAnimType_RafMartinez = 26,
	eCharAnimType_CandyPrison = 27,
	eCharAnimType_Cop_01 = 28,
	eCharAnimType_Cop_02 = 29,
	eCharAnimType_Cop_03 = 30,
	eCharAnimType_Cop_04 = 31,
	eCharAnimType_Cop_05 = 32,
	eCharAnimType_Swat_01 = 33,
	eCharAnimType_UpperWhite_01 = 34,
	eCharAnimType_UpperWhite_02 = 35,
	eCharAnimType_LowerWhite_01 = 36,
	eCharAnimType_LowerWhite_02 = 37,
	eCharAnimType_LowerWhite_03 = 38,
	eCharAnimType_LowerWhite_04 = 39,
	eCharAnimType_Black_01 = 40,
	eCharAnimType_Black_03 = 41,
	eCharAnimType_Chinese_01 = 42,
	eCharAnimType_Chinese_02 = 43,
	eCharAnimType_Columbian_01 = 44,
	eCharAnimType_Columbian_02 = 45,
	eCharAnimType_Columbian_03 = 46,
	eCharAnimType_Columbian_04 = 47,
	eCharAnimType_Columbian_05 = 48,
	eCharAnimType_StreetPunk_01 = 49,
	eCharAnimType_StreetPunk_02 = 50,
	eCharAnimType_StreetPunk_03 = 51,
	eCharAnimType_StreetPunk_04 = 52,
	eCharAnimType_StreetPunk_05 = 53,
	eCharAnimType_Biker_01 = 54,
	eCharAnimType_Biker_02 = 55,
	eCharAnimType_Biker_03 = 56,
	eCharAnimType_CandysGang_01 = 57,
	eCharAnimType_CandysGang_02 = 58,
	eCharAnimType_CandysGang_03 = 59,
	eCharAnimType_CandysGang_04 = 60,
	eCharAnimType_CandysGang_05 = 61,
	eCharAnimType_Security_01 = 62,
	eCharAnimType_Security_02 = 63,
	eCharAnimType_Security_03 = 64,
	eCharAnimType_Security_04 = 65,
	eCharAnimType_Security_05 = 66,
	eCharAnimType_Liquor_01 = 67,
	eCharAnimType_Mercenary_01 = 68,
	eCharAnimType_Mercenary_02 = 69,
	eCharAnimType_Mercenary_03 = 70,
	eCharAnimType_Mercenary_04 = 71,
	eCharAnimType_Mercenary_05 = 72,
	eCharAnimType_Trucker = 73,
	eCharAnimType_Beatnik_01 = 74,
	eCharAnimType_Beatnik_02 = 75,
	eCharAnimType_Hippy_01 = 76,
	eCharAnimType_Hippy_02 = 77,
	eCharAnimType_Hippy_03 = 78,
	eCharAnimType_MiddleBlack_01 = 79,
	eCharAnimType_MiddleBlack_02 = 80,
	eCharAnimType_RichWhiteF_01 = 81,
	eCharAnimType_RichWhiteF_02 = 82,
	eCharAnimType_Pimp_01 = 83,
	eCharAnimType_Pimp_02 = 84,
	eCharAnimType_RichBlack_01 = 85,
	eCharAnimType_RichBlack_02 = 86,
	eCharAnimType_Business_01 = 87,
	eCharAnimType_Business_02 = 88,
	eCharAnimType_FemalePed_01 = 89,
	eCharAnimType_FemalePed_02 = 90,
	eCharAnimType_FemalePed_03 = 91,
	eCharAnimType_FemalePed_04 = 92,
	eCharAnimType_Prisoner_01 = 93,
	eCharAnimType_Prisoner_02 = 94,
	eCharAnimType_Prisoner_03 = 95,
	eCharAnimType_Worker_01 = 96,
	eCharAnimType_Worker_02 = 97,
	eCharAnimType_Worker_03 = 98,
	eCharAnimType_Hooker_01 = 99,
	eCharAnimType_Hooker_02 = 100,
	eCharAnimType_Hooker_03 = 101,
	eCharAnimType_PoorBlack_01 = 102,
	eCharAnimType_PoorBlack_02 = 103,
	eCharAnimType_PoorBlack_03 = 104,
	eCharAnimType_PoorBlackF_01 = 105,
	eCharAnimType_PoorBlackF_02 = 106,
	eCharAnimType_RichWhite_01 = 107,
	eCharAnimType_RichWhite_02 = 108,
	eCharAnimType_Chinese = 109,
	eCharAnimType_ChineseF = 110,
	eCharAnimType_BusinessW_01 = 111,
	eCharAnimType_BusinessW_02 = 112,
	eCharAnimType_TheDriver = 113,
	eCharAnimType_MariaCortez = 114,
	eCharAnimType_Cop01 = 115,
	eCharAnimType_Cop02 = 116,
	eCharAnimType_Cop03 = 117,
	eCharAnimType_Swat = 118,
	eCharAnimType_UpperWhite_03 = 119,
	eCharAnimType_Black_02 = 120,
	eCharAnimType_Hispanic_01 = 121,
	eCharAnimType_Hispanic_02 = 122,
	eCharAnimType_StreetGang_01 = 123,
	eCharAnimType_StreetGang_02 = 124,
	eCharAnimType_StreetGang_03 = 125,
	eCharAnimType_StreetGang_04 = 126,
	eCharAnimType_StreetGang_05 = 127,
	eCharAnimType_CandysRivals_01 = 128,
	eCharAnimType_CandysRivals_02 = 129,
	eCharAnimType_CandysRivals_03 = 130,
	eCharAnimType_CandysRivals_04 = 131,
	eCharAnimType_BikerGang_01 = 132,
	eCharAnimType_BikerGang_02 = 133,
	eCharAnimType_BikerGang_03 = 134,
	eCharAnimType_PoorWhiteF = 135,
	eCharAnimType_MiddleWhite = 136,
	eCharAnimType_MiddleWhiteF = 137,
	eCharAnimType_StreetGang01 = 138,
	eCharAnimType_StreetGang02 = 139,
	eCharAnimType_Tourist_01 = 140,
	eCharAnimType_Tourist_02 = 141,
	eCharAnimType_Jogger_01 = 142,
	eCharAnimType_Jogger_02 = 143,
	eCharAnimType_PoorWhite_01 = 144,
	eCharAnimType_RichWhite = 145,
	eCharAnimType_RichWhiteF = 146,
	eCharAnimType_Homeless_01 = 147,
	eCharAnimType_Homeless_02 = 148,
	eCharAnimType_OfficeWorker_01 = 149,
	eCharAnimType_OfficeWorker_02 = 150,
	eCharAnimType_Student_01 = 151,
	eCharAnimType_Student_02 = 152,
	eCharAnimType_Blader_01 = 153,
	eCharAnimType_Blader_02 = 154,
	eCharAnimType_Hitman = 155,
	eCharAnimType_PoorHispanic = 156,
	eCharAnimType_PoorHispanicF = 157,
	eCharAnimType_MiddleBlack = 158,
	eCharAnimType_BlackGang_01 = 159,
	eCharAnimType_BlackGang_02 = 160,
	eCharAnimType_PrisonGuard_01 = 161,
	eCharAnimType_PrisonGuard_02 = 162,
	eCharAnimType_Trucker_01 = 163,
	eCharAnimType_Trucker_02 = 164,
	eCharAnimType_BusinessF_01 = 165,
	eCharAnimType_BusinessF_02 = 166,
	eCharAnimType_MIB_01 = 167,
	eCharAnimType_MIB_02 = 168,
	eCharAnimType_MIB_03 = 169,
	eCharAnimType_Mcbfemale = 170,
	eCharAnimType_Mcbmale = 171,
	eCharAnimType_Tourist_03 = 172,
	eCharAnimType_Tourist_04 = 173,
	eCharAnimType_Upp_W05 = 174,
	eCharAnimType_End = 175,
};