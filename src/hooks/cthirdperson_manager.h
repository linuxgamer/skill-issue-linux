#pragma once

#include "../libdetour/libdetour.h"
#include "../libsigscan.h"
#include "../features/logs/logs.h"

DETOUR_DECL_TYPE(void, CThirdPersonManager_Update, void* self);

static void Hooked_CThirdPersonManager_Update()
{
	/*
	;)
	*/
}

static void Hook_CThirdPersonManager_Update()
{
	void* original = sigscan_module("client.so", "55 48 89 E5 41 54 4C 8D 25 ? ? ? ? 53 48 89 FB 49 8B 04 24 48 85 C0 74 ? 48 8B 40 38");
	if (original == nullptr)
		return Logs::Error("CThirdPersonManager::Update is nullptr!");

	detour_ctx_t thirdperson_ctx;
	detour_init(&thirdperson_ctx, original, (void*)&Hooked_CThirdPersonManager_Update);

	if (!detour_enable(&thirdperson_ctx))
		Logs::Error("Couldn't hook CThirdPersonManager::Update!");
}