#pragma once

#include "../../../include/angelscript.h"
#include <string>
#include <vector>

struct ASHook
{
	std::string name;
	asIScriptFunction* func;
};

void Hooks_RegisterLibrary(asIScriptEngine* engine);
bool Hooks_GetHooks(const std::string& event, std::vector<ASHook>& out);