#include "Camera.h"
#include "..\plugin\menu.h"

GameCamera* GameCamera::GetInstance()
{
    return ((GameCamera*(__cdecl*)())0x55A60A)();
}

void GameCamera::SetCameraMatrix_Hook()
{
    if (!TheMenu->m_bCustomCameraPos)
        TheMenu->m_mCameraMatrix.pos = camMatrix.pos;
    else
    {
        camMatrix.pos = TheMenu->m_mCameraMatrix.pos;
    }

    if (!TheMenu->m_bCustomCameraRot)
    {
        TheMenu->m_mCameraMatrix.forward = camMatrix.forward;
        TheMenu->m_mCameraMatrix.up = camMatrix.up;
        TheMenu->m_mCameraMatrix.right = camMatrix.right;
    }
    else
    {
        camMatrix.forward = TheMenu->m_mCameraMatrix.forward;
        camMatrix.up = TheMenu->m_mCameraMatrix.up;
        camMatrix.right = TheMenu->m_mCameraMatrix.right;
    }

    ((void(__thiscall*)(GameCamera*))0x55A646)(this);

}
