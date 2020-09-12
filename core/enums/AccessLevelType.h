#pragma once

#include <string>

enum class AccessLevelType
{
    Public,
    Private,
    Protected
};

AccessLevelType strToAccessLevelType(const std::string &str);
std::string accessLevelTypeToStr(AccessLevelType alt);

