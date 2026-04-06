#include "globalvars.h"
#include "../../../../../sdk/interfaces/interfaces.h"
#include "../../globals.h"

void Globalvars_RegisterLibrary(asIScriptEngine* engine)
{
	auto def = engine->GetDefaultNamespace();

	engine->SetDefaultNamespace("GlobalVars");
	{
		engine->SetDefaultAccessMask(ScriptAccessMask::SCRIPT_MASK_ALLOW_GLOBALVARS);
		engine->RegisterGlobalProperty("float realtime", &interfaces::GlobalVars->realtime);
		engine->RegisterGlobalProperty("int framecount", &interfaces::GlobalVars->framecount);
		engine->RegisterGlobalProperty("float absolute_frametime", &interfaces::GlobalVars->absolute_frametime);
		engine->RegisterGlobalProperty("float curtime", &interfaces::GlobalVars->curtime);
		engine->RegisterGlobalProperty("float frametime", &interfaces::GlobalVars->frametime);
		engine->RegisterGlobalProperty("int max_clients", &interfaces::GlobalVars->max_clients);
		engine->RegisterGlobalProperty("int tickcount", &interfaces::GlobalVars->tickcount);
		engine->RegisterGlobalProperty("float interval_per_tick", &interfaces::GlobalVars->interval_per_tick);
		engine->RegisterGlobalProperty("float interpolation_amount", &interfaces::GlobalVars->interpolation_amount);
		engine->RegisterGlobalProperty("int sim_ticks_this_frame", &interfaces::GlobalVars->sim_ticks_this_frame);
		engine->RegisterGlobalProperty("int network_protocol", &interfaces::GlobalVars->network_protocol);
		engine->RegisterGlobalProperty("bool client", &interfaces::GlobalVars->client);
		engine->RegisterGlobalProperty("int nTimestampNetworkingBase", &interfaces::GlobalVars->nTimestampNetworkingBase);
		engine->RegisterGlobalProperty("int nTimestampRandomizeWindow", &interfaces::GlobalVars->nTimestampRandomizeWindow);
	}

	engine->SetDefaultNamespace(def);
}