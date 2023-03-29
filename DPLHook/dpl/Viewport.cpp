#include "Viewport.h"
#include "..\plugin\menu.h"

void CPCViewport::SetFOV(float FOV)
{
	*(float*)((int)this + 0x50C) = FOV;
}

void CPCViewport::SetFOVHooked(float FOV)
{
	if (!TheMenu->m_bCustomCameraFOV)
	{
		TheMenu->m_fCamFOV = FINAL_TO_FOV(FOV);
		SetFOV(FOV);
	}
	else
	{
		SetFOV(FOV_TO_FINAL(TheMenu->m_fCamFOV));
	}

}
