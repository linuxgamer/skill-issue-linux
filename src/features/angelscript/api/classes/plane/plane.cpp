#include "plane.h"

#include "../../../../../sdk/definitions/cbasetrace.h"

void Plane_RegisterClass(asIScriptEngine *engine)
{
	engine->RegisterObjectType("Plane", sizeof(cplane_t), asOBJ_VALUE | asOBJ_POD);

	engine->RegisterObjectProperty("Plane", "Vector3 normal", asOFFSET(cplane_t, normal));
	engine->RegisterObjectProperty("Plane", "float dist", asOFFSET(cplane_t, dist));
	engine->RegisterObjectProperty("Plane", "uint8 type", asOFFSET(cplane_t, type));
	engine->RegisterObjectProperty("Plane", "uint8 signbits", asOFFSET(cplane_t, signbits));
}