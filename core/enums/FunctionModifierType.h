#pragma once

enum class FunctionModifier
{
    Virtual,
    Const,
    PureVirtual,
    Static,
    Override,
    Noexept,
    Constexpr,

    Method,
};


FunctionModifier strToFunctionModifier(const std::string &str);
std::string functionModifierToStr(FunctionModifier fm);
