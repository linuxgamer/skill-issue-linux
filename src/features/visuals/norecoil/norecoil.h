#pragma once

#include "../../../sdk/classes/player.h"
#include "../../../sdk/classes/weaponbase.h"

namespace NoRecoil
{
	void RunOverrideView(CTFPlayer *pLocal, CViewSetup *pView);
	void RunCreateMove(CTFPlayer *pLocal, CTFWeaponBase *pWeapon, CUserCmd *pCmd);
	void RunCalcViewModelView(Vector& angle);
} // namespace NoRecoil