#pragma once

#include "../sdk/definitions/ipanel.h"
#include <cwchar>
#include <string>
#include "../sdk/classes/entity.h"
#include "../sdk/helpers/helper.h"
#include "../sdk/definitions/color.h"
#include "../sdk/classes/weaponbase.h"
#include "../sdk/handle_utils.h"
#include "../settings/settings.h"

#include "../features/esp/esp.h"
#include "../features/aimbot/aimbot.h"
#include "../features/entitylist/entitylist.h"
#include "../features/warp/warp.h"

#if 0
#include "../features/lua/hookmgr.h"
#include "../features/lua/api.h"
#endif

#include "../features/angelscript/api/api.h"
#include "../features/angelscript/api/libraries/hooks/hooks.h"

#include "../core/core.h"

static void AS_VGUIPaint_Callback()
{
	std::vector<ASHook> hooks;
	if (!Hooks_GetHooks("Draw", hooks))
		return;

	auto engine = API::GetScriptEngine();

	for (const auto& hook : hooks)
	{
		asIScriptContext* ctx = engine->RequestContext();

		ctx->Prepare(hook.func);
		ctx->Execute();

		engine->ReturnContext(ctx);
	}
}

DECLARE_VTABLE_HOOK(VGuiPaint, void, (IEngineVGui* thisptr, PaintMode_t paint))
{
	originalVGuiPaint(thisptr, paint);

	// I don't trust
	// C++'s static initialization
	if (!gApp.IsInitialized())
		return gApp.Setup();

	if (interfaces::Engine->IsTakingScreenshot())
		return;

	if (paint & PAINT_UIPANELS)
	{
		interfaces::Surface->StartDrawing();

		#if 0
		if (LuaHookManager::HasHooks("Draw"))
			LuaHookManager::Call(Lua::m_luaState, "Draw", 0);
		#endif
		AS_VGUIPaint_Callback();

		FontManager::SetFont(ESP::GetFont());

		CTFPlayer* pLocal = EntityList::GetLocal();
		if (pLocal)
		{
			ESP::Run(pLocal);
			Aimbot::RunPaint();
		}

		// compile time
		if (Settings::menu_open)
		{
			Color color = {255, 255, 255, 255};
			helper::draw::TextShadow(10, 10, color, "Skill Issue");
			helper::draw::TextShadow(10, 30, color, "Build date: " __DATE__ " " __TIME__);
		}

		interfaces::Surface->FinishDrawing();
	}
}

inline void HookEngineVGuiPaint()
{
	INSTALL_VTABLE_HOOK(VGuiPaint, interfaces::EngineVGui, 15);

	#ifdef DEBUG
	constexpr Color_t color = {100, 255, 100, 255};
	helper::console::ColoredPrint("EngineVGui::Paint hooked\n", color);
	#endif
}