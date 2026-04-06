#include "vector3.h"

#include "../../../../../sdk/definitions/vector.h"

#define VECTOR_CLASSNAME "Vector3"

void Vector3_Default(Vector *self)
{
	new (self) Vector();
}

void Vector3_Init(float x, float y, float z, Vector *self)
{
	new (self) Vector(x, y, z);
}

Vec2 Get2D(Vector *self)
{
	return {self->x, self->y};
}

void Vector3_RegisterClass(asIScriptEngine *engine)
{
	engine->RegisterObjectType(VECTOR_CLASSNAME, sizeof(Vector),
				   asOBJ_VALUE | asOBJ_POD | asGetTypeTraits<Vector>());

	engine->RegisterObjectBehaviour(VECTOR_CLASSNAME, asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(Vector3_Default), asCALL_CDECL_OBJLAST);
	engine->RegisterObjectBehaviour(VECTOR_CLASSNAME, asBEHAVE_CONSTRUCT, "void f(float, float, float)", asFUNCTION(Vector3_Init), asCALL_CDECL_OBJLAST);

	engine->RegisterObjectProperty(VECTOR_CLASSNAME, "float x", offsetof(Vector, x));
	engine->RegisterObjectProperty(VECTOR_CLASSNAME, "float y", offsetof(Vector, y));
	engine->RegisterObjectProperty(VECTOR_CLASSNAME, "float z", offsetof(Vector, z));

	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3& opAssign(const Vector3 &in)", asMETHODPR(Vec3, operator=, (const Vec3&), Vec3&), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "float& opIndex(int)", asMETHODPR(Vec3, operator[], (int), float&), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "float opIndex(int) const", asMETHODPR(Vec3, operator[], (int) const, float), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "bool opEquals(const Vector3 &in)", asMETHODPR(Vec3, operator==, (const Vec3&) const, bool), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "bool opCmp(const Vector3 &in)", asMETHODPR(Vec3, operator!=, (const Vec3&) const, bool), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "bool opImplConv() const", asMETHODPR(Vec3, operator bool, () const, bool), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3& opAddAssign(const Vector3 &in)", asMETHODPR(Vec3, operator+=, (const Vec3&), Vec3&), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3& opSubAssign(const Vector3 &in)", asMETHODPR(Vec3, operator-=, (const Vec3&), Vec3&), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3& opMulAssign(const Vector3 &in)", asMETHODPR(Vec3, operator*=, (const Vec3&), Vec3&), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3& opDivAssign(const Vector3 &in)", asMETHODPR(Vec3, operator/=, (const Vec3&), Vec3&), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3& opAddAssign(float)", asMETHODPR(Vec3, operator+=, (float), Vec3&), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3& opSubAssign(float)", asMETHODPR(Vec3, operator-=, (float), Vec3&), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3& opMulAssign(float)", asMETHODPR(Vec3, operator*=, (float), Vec3&), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3& opDivAssign(float)", asMETHODPR(Vec3, operator/=, (float), Vec3&), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 opAdd(const Vector3 &in)", asMETHODPR(Vec3, operator+, (const Vec3&) const, Vec3), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 opSub(const Vector3 &in)", asMETHODPR(Vec3, operator-, (const Vec3&) const, Vec3), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 opMul(const Vector3 &in)", asMETHODPR(Vec3, operator*, (const Vec3&) const, Vec3), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 opDiv(const Vector3 &in)", asMETHODPR(Vec3, operator/, (const Vec3&) const, Vec3), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 opAdd(float)", asMETHODPR(Vec3, operator+, (float) const, Vec3), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 opSub(float)", asMETHODPR(Vec3, operator-, (float) const, Vec3), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 opMul(float)", asMETHODPR(Vec3, operator*, (float) const, Vec3), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 opDiv(float)", asMETHODPR(Vec3, operator/, (float) const, Vec3), asCALL_THISCALL);

	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 To2D()", asMETHOD(Vector, To2D), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "float Length() const", asMETHOD(Vector, Length), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "float LengthSqr() const", asMETHOD(Vector, LengthSqr), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "float Normalize() const", asMETHOD(Vector, Normalize), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "float Normalize2D() const", asMETHOD(Vector, Normalize2D), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 Normalized()", asMETHOD(Vector, Normalized), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 Normalized2D()", asMETHOD(Vector, Normalized2D), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector2 Get2D()", asFUNCTION(Get2D), asCALL_CDECL_OBJFIRST);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "float Length2D() const", asMETHOD(Vector, Length2D), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "float Length2DSqr() const", asMETHOD(Vector, Length2DSqr), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "float DistTo() const", asMETHOD(Vector, DistTo), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "float DistTo2D() const", asMETHOD(Vector, DistTo2D), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "float DistToSqr() const", asMETHOD(Vector, DistToSqr), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "float DistTo2DSqr() const", asMETHOD(Vector, DistTo2DSqr), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "float Dot() const", asMETHOD(Vector, Dot), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 Cross()", asMETHOD(Vector, Cross), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "bool IsZero() const", asMETHOD(Vector, IsZero), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 ToAngle() const", asMETHOD(Vector, ToAngle), asCALL_THISCALL);
	engine->RegisterObjectMethod(VECTOR_CLASSNAME, "Vector3 FromAngle() const", asMETHOD(Vector, FromAngle), asCALL_THISCALL);
}