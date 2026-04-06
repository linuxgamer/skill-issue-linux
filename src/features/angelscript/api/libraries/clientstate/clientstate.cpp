#include "clientstate.h"

#include "../../globals.h"

#include "../../../../../sdk/definitions/cclientstate.h"
#include "../../../../../sdk/interfaces/interfaces.h"
#include "../../../../logs/logs.h"

void ForceFullUpdate()
{
	// xref: Requesting full game update
	if (interfaces::ClientState == nullptr)
		return Logs::Error("ClientState is null!");

	// I should probably add this to the clientstate def
	// But I don't use it anywhere in the code sooo

	using ForceFullUpdateFn = void (*)(CClientState *self);
	static ForceFullUpdateFn original_ForceFullUpdate =
	    reinterpret_cast<ForceFullUpdateFn>(sigscan_module("engine.so", "83 BF B8 01 00 00 FF 74 ? 55"));
	if (original_ForceFullUpdate == nullptr)
		return Logs::Error("ForceFullUpdate is null!");

	original_ForceFullUpdate(reinterpret_cast<CClientState *>(interfaces::ClientState));
}

void ClientState_RegisterLibrary(asIScriptEngine *engine)
{
	auto defNamespace = engine->GetDefaultNamespace();

	engine->SetDefaultNamespace("ClientState");
	{
		engine->SetDefaultAccessMask(ScriptAccessMask::SCRIPT_MASK_ALLOW_CLIENTSTATE);

		auto clientstate = static_cast<CClientState *>(interfaces::ClientState);

		engine->RegisterGlobalFunction("void ForceFullUpdate()", asFUNCTION(ForceFullUpdate), asCALL_CDECL);

		engine->RegisterGlobalProperty("int m_Socket", &clientstate->m_Socket);
		engine->RegisterGlobalProperty("uint m_nChallengeNr", &clientstate->m_nChallengeNr);
		engine->RegisterGlobalProperty("double m_flConnectTime", &clientstate->m_flConnectTime);
		engine->RegisterGlobalProperty("int m_nRetryNumber", &clientstate->m_nRetryNumber);
		engine->RegisterGlobalProperty("int m_retryChallenge", &clientstate->m_retryChallenge);
		engine->RegisterGlobalProperty("int m_nSignonState", &clientstate->m_nSignonState);
		engine->RegisterGlobalProperty("double m_flNextCmdTime", &clientstate->m_flNextCmdTime);
		engine->RegisterGlobalProperty("int m_nServerCount", &clientstate->m_nServerCount);
		engine->RegisterGlobalProperty("uint64 m_ulGameServerSteamID", &clientstate->m_ulGameServerSteamID);
		engine->RegisterGlobalProperty("int m_nCurrentSequence", &clientstate->m_nCurrentSequence);
		engine->RegisterGlobalProperty("int m_nDeltaTick", &clientstate->m_nDeltaTick);
		engine->RegisterGlobalProperty("bool m_bPaused", &clientstate->m_bPaused);
		engine->RegisterGlobalProperty("float m_flPausedExpireTime", &clientstate->m_flPausedExpireTime);
		engine->RegisterGlobalProperty("int m_nViewEntity", &clientstate->m_nViewEntity);
		engine->RegisterGlobalProperty("int m_nPlayerSlot", &clientstate->m_nPlayerSlot);
		engine->RegisterGlobalProperty("int m_nMaxClients", &clientstate->m_nMaxClients);
		engine->RegisterGlobalProperty("bool m_bRestrictServerCommands", &clientstate->m_bRestrictServerCommands);
		engine->RegisterGlobalProperty("bool m_bRestrictClientCommands", &clientstate->m_bRestrictClientCommands);
		engine->RegisterGlobalProperty("bool insimulation", &clientstate->insimulation);
		engine->RegisterGlobalProperty("int oldtickcount", &clientstate->oldtickcount);
		engine->RegisterGlobalProperty("float m_tickRemainder", &clientstate->m_tickRemainder);
		engine->RegisterGlobalProperty("float m_frameTime", &clientstate->m_frameTime);
		engine->RegisterGlobalProperty("int lastoutgoingcommand", &clientstate->lastoutgoingcommand);
		engine->RegisterGlobalProperty("int chokedcommands", &clientstate->chokedcommands);
		engine->RegisterGlobalProperty("int last_command_ack", &clientstate->last_command_ack);
		engine->RegisterGlobalProperty("int command_ack", &clientstate->command_ack);
		engine->RegisterGlobalProperty("int m_nSoundSequence", &clientstate->m_nSoundSequence);
		engine->RegisterGlobalProperty("bool ishltv", &clientstate->ishltv);
		engine->RegisterGlobalProperty("bool isreplay", &clientstate->isreplay);
		engine->RegisterGlobalProperty("int demonum", &clientstate->demonum);
		engine->RegisterGlobalProperty("bool m_bMarkedCRCsUnverified", &clientstate->m_bMarkedCRCsUnverified);
	}

	engine->SetDefaultNamespace(defNamespace);
}