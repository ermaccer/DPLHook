#include "common.h"
#include "VehicleManager.h"
#include "ResourceManager.h"
#include "LifeSystem.h"
#include "LifeInstances.h"
#include "LifeAcquirableVehicleManager.h"
#include "CharacterCategoryManager.h"
#include "ResidentArea.h"
#include <iostream>
#include "..\plugin\menu.h"
#include "..\eNotifManager.h"

void CreateVehicle(tVehicleModelUID id, Vector* pos)
{
    CVehicle* pCar;
    GetResourceManager()->SetEntityPriority(0, id, true);


    if (GetResourceManager()->IsEntityLoaded(0, id))
    {   
        CVehicleSpecification::g_bTankEnable = true;
        CVehicle** out = GetVehicleManager()->CreateVehicle(&pCar, id, pos->X, pos->Y, pos->Z, 25.0f, 3.14f, 0, 1, 1);
        pCar = *out;
        CVehicleSpecification::g_bTankEnable = false;

        if (pCar)
        {
            GetLifeAcquirableVehicleManager()->AddVehicle(pCar, 1);
            if (TheMenu->m_bSetVehicleColor)
                pCar->SetColor(TheMenu->m_vVehicleColor.x, TheMenu->m_vVehicleColor.y, TheMenu->m_vVehicleColor.z);

            CPlayerDriverBehaviour* player = GetLifeSystem()->GetPlayer()->GetDriverBehaviour();
            CCharacter* chr = player->GetCharacter();

            if (TheMenu->m_bForceEnterVehicle)
                chr->EnterVehicle(pCar, 0, true, true);

            Notifications->SetNotificationTime(2500);
            Notifications->PushNotification("Vehicle %d [0x%X] created!", id, pCar);
        }
        else
        {
            Notifications->SetNotificationTime(2500);
            Notifications->PushNotification("Failed to create %d!", id);
        }
    }
    else
    {
        Notifications->SetNotificationTime(2500);
        Notifications->PushNotification("Required assets for %d are not loaded yet, try again.", id);
    }



}

void GiveWeaponToPlayer(EWeapons eWeapon)
{
    CPlayerDriverBehaviour* player = GetLifeSystem()->GetPlayer()->GetDriverBehaviour();

    CCharacterWeapons* weaps = player->GetWeapons();
    weaps->AddWeapon(eWeapon, 9999, 1);
}

void TeleportPlayer(Vector* pos)
{
    if (!GetLifeSystem())
        return;
    CPlayerDriverBehaviour* player = GetLifeSystem()->GetPlayer()->GetDriverBehaviour();
    
    if (!player)
        return;

    Vector4 newPos = { pos->X, pos->Y, pos->Z };
    player->GetCharacter()->SetPosition(&newPos);
}

CWeapon* GetPlayerWeapon()
{
    if (!GetLifeSystem())
        return nullptr;
    CPlayerDriverBehaviour* player = GetLifeSystem()->GetPlayer()->GetDriverBehaviour();

    if (!player)
        return nullptr;

    return player->GetCharacter()->GetWeapon();
}

void SetPlayerModel(int model)
{
    if (!GetLifeSystem())
        return;
    CCharacter* player = GetLifeSystem()->GetPlayer()->GetDriverBehaviour()->GetCharacter();

    if (!player)
        return;

    if (GetResourceManager()->IsEntityPresent(2, model))
    {
        GetResourceManager()->SetEntityPriority(2, model, 1);
        GetCCM()->SetPlayerAvatar(model);
        player->SetModel(model);
        Notifications->SetNotificationTime(2500);
        Notifications->PushNotification("Set player model as %d!", model);
    }
    else
    {
        Notifications->SetNotificationTime(2500);
        Notifications->PushNotification("Model %d is not valid or not present!", model);
    }

}
