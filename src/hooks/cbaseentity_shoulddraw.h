#pragma once

#include "../settings/settings.h"
#include "../libdetour/libdetour.h"
#include "../libsigscan.h"

#include "../sdk/classes/entity.h"

#include "../features/entitylist/entitylist.h"
#include "../features/logs/logs.h"

static detour_ctx_t baseentity_shoulddraw;
DETOUR_DECL_TYPE(bool, CBaseEntity_ShouldDraw, CBaseEntity* self);

static bool Hooked_CBaseEntity_ShouldDraw(CBaseEntity* self)
{
	if (self == nullptr)
		return false;

	/*if (self->GetClassID() == ETFClassID::CTFViewModel)
		if (auto pLocal = EntityList::GetLocal(); pLocal != nullptr && pLocal->IsAlive() && pLocal->InCond(TF_COND_ZOOMED))
			return Settings::Misc.no_zoom;
	*/

	bool ret;
	DETOUR_ORIG_GET(&baseentity_shoulddraw, ret, CBaseEntity_ShouldDraw, self);

	return ret;
}

static void Hook_CBaseEntity_ShouldDraw()
{
	void* original = sigscan_module("client.so", "31 C0 80 BF AC 00 00 00 0A");
	detour_init(&baseentity_shoulddraw, original, (void*)&Hooked_CBaseEntity_ShouldDraw);

	if (!detour_enable(&baseentity_shoulddraw))
		Logs::Error("Couldn't hook C_BaseEntity::ShouldDraw");
}