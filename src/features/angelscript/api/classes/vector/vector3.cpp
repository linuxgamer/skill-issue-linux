#include "vector3.h"

#include "../../../../../sdk/definitions/vector.h"

void Vector3_Default(Vector* self)
{
	new (self) Vector();
}

void Vector3_Init(float x, float y, float z, Vector* self)
{
	new (self) Vector(x, y, z);
}

void Vector3_RegisterClass(asIScriptEngine *engine)
{
	engine->RegisterObjectType("Vector", sizeof(Vector), asOBJ_VALUE | asOBJ_POD | asGetTypeTraits<Vector>());

	engine->RegisterObjectBehaviour("Vector", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(Vector3_Default), asCALL_CDECL_OBJLAST);
	engine->RegisterObjectBehaviour("Vector", asBEHAVE_CONSTRUCT, "void f(float, float, float)", asFUNCTION(Vector3_Init), asCALL_CDECL_OBJLAST);

	engine->RegisterObjectProperty("Vector", "float x", offsetof(Vector, x));
	engine->RegisterObjectProperty("Vector", "float y", offsetof(Vector, y));
	engine->RegisterObjectProperty("Vector", "float z", offsetof(Vector, z));

	engine->RegisterObjectMethod("Vector", "Vector To2D()", asMETHOD(Vector, To2D), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "float Length() const", asMETHOD(Vector, Length), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "float LengthSqr() const", asMETHOD(Vector, LengthSqr), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "float Normalize() const", asMETHOD(Vector, Normalize), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "float Normalize2D() const", asMETHOD(Vector, Normalize2D), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "Vector Normalized()", asMETHOD(Vector, Normalized), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "Vector Normalized2D()", asMETHOD(Vector, Normalized2D), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "Vector Get2D()", asMETHOD(Vector, Get2D), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "float Length2D() const", asMETHOD(Vector, Length2D), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "float Length2DSqr() const", asMETHOD(Vector, Length2DSqr), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "float DistTo() const", asMETHOD(Vector, DistTo), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "float DistTo2D() const", asMETHOD(Vector, DistTo2D), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "float DistToSqr() const", asMETHOD(Vector, DistToSqr), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "float DistTo2DSqr() const", asMETHOD(Vector, DistTo2DSqr), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "float Dot()", asMETHOD(Vector, Dot), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "Vector Cross()", asMETHOD(Vector, Cross), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "bool IsZero() const", asMETHOD(Vector, IsZero), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "Vector ToAngle()", asMETHOD(Vector, ToAngle), asCALL_THISCALL);
	engine->RegisterObjectMethod("Vector", "Vector FromAngle()", asMETHOD(Vector, FromAngle), asCALL_THISCALL);
}