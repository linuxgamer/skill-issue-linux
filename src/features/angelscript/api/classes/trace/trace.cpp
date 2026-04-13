#include "trace.h"

#include "../../../../../sdk/definitions/cgametrace.h"

void Trace_RegisterClass(asIScriptEngine *engine)
{
	engine->RegisterObjectType("Trace", sizeof(CGameTrace), asOBJ_VALUE | asOBJ_POD);

	engine->RegisterObjectProperty("Trace", "Vector3 startpos", asOFFSET(CBaseTrace, startpos));
	engine->RegisterObjectProperty("Trace", "Vector3 endpos", asOFFSET(CBaseTrace, endpos));
	engine->RegisterObjectProperty("Trace", "Plane plane", asOFFSET(CBaseTrace, plane));
	engine->RegisterObjectProperty("Trace", "float fraction", asOFFSET(CBaseTrace, fraction));
	engine->RegisterObjectProperty("Trace", "int contents", asOFFSET(CBaseTrace, contents));
	engine->RegisterObjectProperty("Trace", "uint16 dispFlags", asOFFSET(CBaseTrace, dispFlags));
	engine->RegisterObjectProperty("Trace", "bool allsolid", asOFFSET(CBaseTrace, allsolid));
	engine->RegisterObjectProperty("Trace", "bool startsolid", asOFFSET(CBaseTrace, startsolid));
	engine->RegisterObjectProperty("Trace", "float fractionleftsolid", asOFFSET(CGameTrace, fractionleftsolid));
	engine->RegisterObjectProperty("Trace", "Surface surface", asOFFSET(CGameTrace, surface));
	engine->RegisterObjectProperty("Trace", "int hitgroup", asOFFSET(CGameTrace, hitgroup));
	engine->RegisterObjectProperty("Trace", "int16 physicsbone", asOFFSET(CGameTrace, physicsbone));
	engine->RegisterObjectProperty("Trace", "Entity@ ent", asOFFSET(CGameTrace, m_pEnt));
	engine->RegisterObjectProperty("Trace", "int hitbox", asOFFSET(CGameTrace, hitbox));

	engine->RegisterObjectMethod("Trace", "bool DidHit()", asMETHOD(CGameTrace, DidHit), asCALL_THISCALL);
}