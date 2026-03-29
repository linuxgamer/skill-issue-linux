#include "api.h"

#include "../../../sdk/interfaces/interfaces.h"

#define AS_USE_STLNAMES 1
#include "libraries/client/client.h"
#include "libraries/clientstate/clientstate.h"
#include "classes/convar/convar.h"
#include "libraries/input/input.h"
#include "libraries/render/render.h"
#include "classes/drawmodelcontext/drawmodelcontext.h"
#include "classes/gameevent/event.h"
#include "libraries/materials/materials.h"
#include "classes/material/mat.h"
#include "classes/texture/texture.h"
#include "classes/viewsetup/viewsetup.h"
#include "classes/entity/entity.h"
#include "classes/usercmd/usercmd.h"
#include "libraries/draw/draw.h"
#include "libraries/hooks/hooks.h"
#include "libraries/entitylist/entitylist.h"
#include "../add_on/scriptstdstring/scriptstdstring.h"
#include "../add_on/scriptarray/scriptarray.h"
#include "libraries/common/common.h"
#include "classes/vector/vector3.h"
#include "enums/enums.h"
#include "libraries/engine/engine.h"
#include "globals.h"

static bool s_bInitialized = false;

// I don't like singletons, but I couldn't
// think of a better way of doing it
asIScriptContext* API::GetScriptContext()
{
	return ::GetScriptContext();
}

asIScriptEngine* API::GetScriptEngine()
{
	return ::GetScriptEngine();
}

void MessageCallback(const asSMessageInfo* msg, void* param)
{
	const char* type = "ERR";
	if (msg->type == asMSGTYPE_WARNING) type = "WARN";
	else if (msg->type == asMSGTYPE_INFORMATION) type = "INFO";

	interfaces::Cvar->ConsolePrintf("%s (line: %d, column: %d): %s\n", type, msg->row, msg->col, msg->message);
}

void API::Initialize()
{
	if (s_bInitialized)
		return;

	auto engine = GetScriptEngine();

	engine->SetMessageCallback(asFUNCTION(MessageCallback), 0, asCALL_CDECL);

	RegisterStdString(engine);
	RegisterScriptArray(engine, true);
	Enums_Register(engine);
	Common_RegisterLibrary(engine);
	Vector3_RegisterClass(engine);
	Engine_RegisterLibrary(engine);
	Entity_RegisterClass(engine);
	UserCmd_RegisterClass(engine);
	ViewSetup_RegisterClass(engine);
	Material_RegisterClass(engine);
	GameEvent_RegisterClass(engine);
	DrawModelContext_RegisterClass(engine);
	ClientState_RegisterLibrary(engine);
	Hooks_RegisterLibrary(engine);
	Draw_RegisterLibrary(engine);
	Texture_RegisterClass(engine);
	ConVar_RegisterClass(engine);
	Materials_RegisterLibrary(engine);
	Interface_EntityList_Register(engine);
	Render_RegisterLibrary(engine);
	Input_RegisterLibrary(engine);
	Client_RegisterLibrary(engine);

	s_bInitialized = true;
}

void API::Unitialize()
{
	GetScriptContext()->Release();
	GetScriptEngine()->ShutDownAndRelease();

	s_bInitialized = false;
}

bool API::IsInitialized()
{
	return s_bInitialized;
}

bool API::RunCode(const std::string& text)
{
	auto engine = GetScriptEngine();

	asIScriptModule* mod = engine->GetModule("code", asGM_ALWAYS_CREATE);

	mod->AddScriptSection("script", text.c_str());
	mod->Build();

	auto ctx = GetScriptContext();
	auto func = mod->GetFunctionByDecl("void main()");

	if (!func)
	{
		interfaces::Cvar->ConsolePrintf("\"void main()\" function is missing!\n");
		return false;
	}

	ctx->Prepare(func);

	if (ctx->Execute() != asEXECUTION_FINISHED)
		interfaces::Cvar->ConsolePrintf("Execution could not finish!\n");

	ctx->Unprepare();
	return true;
}