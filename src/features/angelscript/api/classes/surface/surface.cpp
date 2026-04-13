#include "surface.h"

#include "../../../../../sdk/definitions/cmodel.h"

void Surface_RegisterClass(asIScriptEngine *engine)
{
	engine->RegisterObjectType("Surface", sizeof(csurface_t), asOBJ_VALUE | asOBJ_POD);

	engine->RegisterObjectProperty("Surface", "string name", asOFFSET(csurface_t, name));
	engine->RegisterObjectProperty("Surface", "int16 surfaceProps", asOFFSET(csurface_t, surfaceProps));
	engine->RegisterObjectProperty("Surface", "uint8 flags", asOFFSET(csurface_t, flags));
}