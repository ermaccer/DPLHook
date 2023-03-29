#pragma once

#define FOV_TO_FINAL(X) ((X) * 0.017453292f )
#define FINAL_TO_FOV(X) ((X) / 0.017453292f )


class CPCViewport {
public:
	void SetFOV(float FOV);

	void SetFOVHooked(float FOV);
};