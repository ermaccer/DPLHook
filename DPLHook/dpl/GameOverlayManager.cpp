#include "GameOverlayManager.h"
#include "..\plugin\menu.h"

void CGameOverlayManager::Draw(int Viewport)
{
	((void(__thiscall*)(CGameOverlayManager*, int))0x4B7F36)(this, Viewport);
}

void CGameOverlayManager::DrawHooked(int Viewport)
{
	if (TheMenu->m_bDisableHUD)
		return;
	Draw(Viewport);
}

void COverheadMap::Draw(int Viewport)
{
	((void(__thiscall*)(COverheadMap*, int))0x4B9EF1)(this, Viewport);
}

void COverheadMap::DrawHooked(int Viewport)
{
	if (TheMenu->m_bDisableHUD)
		return;
	Draw(Viewport);
}
