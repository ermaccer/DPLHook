#pragma once
#include "..\core\Matrix.h"

class GameCamera {
public:
	Matrix camMatrix;
	static GameCamera* GetInstance();
	void SetCameraMatrix_Hook();
};

