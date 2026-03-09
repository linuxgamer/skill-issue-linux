#include "../libraries.h"
#include "../../esp/esp.h"

namespace LuaFuncs
{
	namespace esp
	{
		const luaL_Reg methods[]
		{
			{"Register", Register},
			{"Unregister", Unregister},
			{"UnregisterAll", UnregisterAll},
			{nullptr, nullptr}
		};

		void open(lua_State* L)
		{
			lua_newtable(L);
			luaL_setfuncs(L, methods, 0);
			lua_setglobal(L, "esp");
		}

		int UnregisterAll(lua_State* L)
		{
			ESP::m_luaElements.clear();
			return 0;
		}

		/*
		esp.Register("id", "text", (int)alignment, {r, g, b, a}, function(entity, data)
			return true
		end): bool
		*/
		int Register(lua_State* L)
		{
			const char* id = luaL_checkstring(L, 1);

			for (const auto& element : ESP::m_luaElements)
			{
				const std::string& curID = element->GetID();
				if (curID == id)
				{
					lua_pushboolean(L, 0);
					return 1;
				}
			}

			const char* text = luaL_checkstring(L, 2);
			int alignment = luaL_checkinteger(L, 3);

			luaL_checktype(L, 4, LUA_TTABLE);
			Color color{};
			// get the color from lua
			{
				lua_getfield(L, 4, "r");
				int r = luaL_checkinteger(L, -1);
				lua_pop(L, 1);

				lua_getfield(L, 4, "g");
				int g = luaL_checkinteger(L, -1);
				lua_pop(L, 1);

				lua_getfield(L, 4, "b");
				int b = luaL_checkinteger(L, -1);
				lua_pop(L, 1);

				lua_getfield(L, 4, "a");
				int a = luaL_optinteger(L, -1, 255);
				lua_pop(L, 1);

				color.SetColor(r, g, b, a);
			}

			luaL_checktype(L, 5, LUA_TFUNCTION);
    			lua_pushvalue(L, 5);
    			int callbackRef = luaL_ref(L, LUA_REGISTRYINDEX);

			ESP::m_luaElements.push_back(std::make_unique<LuaElement>(id, text, callbackRef, static_cast<ESP_ALIGNMENT>(alignment), color));

			lua_pushboolean(L, 1);
			return 1;
		}

		/*
		esp.Unregister("id"): bool
		*/
		int Unregister(lua_State* L)
		{
			const char* id = luaL_checkstring(L, 1);

			for (auto it = ESP::m_luaElements.begin(); it != ESP::m_luaElements.end(); it++)
			{
				if (it->get()->GetID() == id)
				{
					ESP::m_luaElements.erase(it);
					lua_pushboolean(L, 1);
					return 1;
				}
			}

			lua_pushboolean(L, 0);
			return 1;
		}
	}
}