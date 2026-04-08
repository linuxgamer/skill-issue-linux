#include "binds.h"

#include "../../../../binds/binds.h"

Hotkey* CreateHotkey(const std::string& name, ImGuiKey key, int type, int mode)
{
	InputType it = static_cast<InputType>(type);

	if (it > InputType::VirtualKey || it < InputType::None)
		return nullptr;

	HotkeyMode hm = static_cast<HotkeyMode>(mode);

	if (hm < HotkeyMode::Off || hm > HotkeyMode::Always)
		return nullptr;

	if (key < ImGuiKey_NamedKey_BEGIN || key >= ImGuiKey_NamedKey_END)
		return nullptr;

	auto hk = gBinds.RegisterHotkey(name.c_str());

	hk->m_iKey = static_cast<int>(key);
	hk->m_iType = it;
	hk->m_iMode = hm;
	hk->m_bIsPressed = false;
	hk->m_bCapturing = false;
	hk->m_bState = false;

	return hk;
}

void Binds_RegisterLibrary(asIScriptEngine *engine)
{
	auto def = engine->GetDefaultNamespace();

	engine->SetDefaultNamespace("Binds");
	{
		engine->RegisterGlobalFunction("Bind@ CreateBind(const string &in name, ImGuiKey key, int type, int mode)", asFUNCTION(CreateHotkey), asCALL_CDECL);
	}

	engine->SetDefaultNamespace(def);
}