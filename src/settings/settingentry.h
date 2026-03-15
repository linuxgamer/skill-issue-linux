#pragma once

#include <cstdint>
#include <fstream>
#include <functional>
#include <string_view>
#include <variant>
#include "type.h"

struct SettingEntry
{
	std::string_view name;
	SettingType type;

	std::function<void(std::ofstream&)> save;
	std::function<void(const std::string&)> load;

	std::function<std::string()> get;
	std::function<void(const std::string&)> set;
};