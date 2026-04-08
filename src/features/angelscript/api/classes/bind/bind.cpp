#include "bind.h"

#include "../../../../binds/binds.h"

bool DeleteHotkey(Hotkey* hk)
{
	if (hk == nullptr)
		return false;

	auto& vec = gBinds.GetHotkeys();

	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		if (it->get() == nullptr)
			continue;

		if (it->get()->m_strName == hk->m_strName)
		{
			vec.erase(it);
			return true;
		}
	}

	return false;
}

bool DrawHotkey(Hotkey* hk, const std::string& label)
{
	if (hk == nullptr)
		return false;

	return gBinds.RenderHotkey(label.c_str(), hk);
}

void Bind_RegisterClass(asIScriptEngine *engine)
{
	engine->RegisterObjectType("Bind", 0, asOBJ_REF | asOBJ_NOCOUNT);

	engine->RegisterObjectMethod("Bind", "bool IsActive()", asMETHOD(Hotkey, IsActive), asCALL_THISCALL);
	engine->RegisterObjectMethod("Bind", "bool IsEnabled()", asMETHOD(Hotkey, IsEnabled), asCALL_THISCALL);

	engine->RegisterObjectProperty("Bind", "ImGuiKey m_iKey", asOFFSET(Hotkey, m_iKey));
	engine->RegisterObjectProperty("Bind", "bool m_bState", asOFFSET(Hotkey, m_bState));
	engine->RegisterObjectProperty("Bind", "bool m_bIsPressed", asOFFSET(Hotkey, m_bIsPressed));
	engine->RegisterObjectProperty("Bind", "bool m_bCapturing", asOFFSET(Hotkey, m_bCapturing));
	engine->RegisterObjectProperty("Bind", "BindMode m_iMode", asOFFSET(Hotkey, m_iMode));
	engine->RegisterObjectProperty("Bind", "int m_iType", asOFFSET(Hotkey, m_iType));

	engine->RegisterObjectMethod("Bind", "bool Delete()", asFUNCTION(DeleteHotkey), asCALL_CDECL_OBJFIRST);
	engine->RegisterObjectMethod("Bind", "bool Draw(const string &in label)", asFUNCTION(DrawHotkey), asCALL_CDECL_OBJFIRST);
}