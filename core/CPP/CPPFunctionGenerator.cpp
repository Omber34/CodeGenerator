//
// Created by Herman on 21.07.2020.
//

#include <fmt/format.h>
#include "CPPFunctionGenerator.h"
#include "CPPHelper.h"

std::string CPPFunctionGenerator::generateBody(const Function &func) {
    return "{\n\tthrow std::logic_error(\"function has no impl\");\n }";
}

std::string CPPFunctionGenerator::generateArgString(const FunctionArgument &arg)
{
    return  fmt::format("{} {}", language->parseValueType(arg.type), arg.name);
}

std::string CPPFunctionGenerator::generateArgumentString(const Function &func) {
    if (func.arguments.empty())
        return "";
    std::string result = generateArgString(func.arguments[0]);
    for (size_t i {1}; i < func.arguments.size(); ++i)
    {
        result += ", ";
        result += generateArgString(func.arguments[i]);

        if (!func.arguments[i].defaultValue.empty())
            result += " = " + func.arguments[i].defaultValue;
    }
    return result;
}

std::string CPPFunctionGenerator::generateForwardMods(const Function &func) {
    std::string result;
    auto pred = [](FunctionModifier fm) {
        switch (fm) {
            case FunctionModifier::Virtual:
            case FunctionModifier::Constexpr:
            case FunctionModifier::Static:
                return true;
            default:
                return false;
        }
    };

    auto it = std::find_if(func.modifiers.begin(), func.modifiers.end(), pred);
    while (it != func.modifiers.end())
    {
        result += language->parseFunctionModifier(*it) + " ";
        it = std::find_if(++it, func.modifiers.end(), pred);
    }
    return result;
}

std::string CPPFunctionGenerator::generateBackMods(const Function &func) {
    std::string result;
    auto pred = [](FunctionModifier fm) {
        switch (fm) {
            case FunctionModifier::Const:
            case FunctionModifier::PureVirtual:
            case FunctionModifier::Override:
            case FunctionModifier::Noexept:
                return true;
            default:
                return false;
        }
    };

    auto it = std::find_if(func.modifiers.begin(), func.modifiers.end(), pred);
    while (it != func.modifiers.end())
    {
        if ((*it) == FunctionModifier::PureVirtual){
            result += language->parseFunctionModifier(*it) ;
        } else {
            result = language->parseFunctionModifier(*it) + " " + result;
        }
        it = std::find_if(++it, func.modifiers.end(), pred);
    }
    return result;
}

CPPFunctionGenerator::CPPFunctionGenerator() : FunctionGenerator() {
    functionPattern =   "{0} {1} {2}({3}) {4} \n "
                        "{5}";
    language = std::make_shared<CPPHelper>();
}

std::string CPPFunctionGenerator::generateFunction(const Function &func) {
    std::string result;
    result = fmt::format(functionPattern,
                         generateForwardMods(func),
                         language->parseValueType(func.returnValue.type),
                         generateFullName(func),
                         generateArgumentString(func),
                         generateBackMods(func),
                         generateBody(func)
    );
    return result;
}

std::string CPPFunctionGenerator::generateFullName(const Function &func) {
    std::string result ;
    if (!func.owner.expired())
    {
        result = func.owner.lock()->getName() + "::";
    }
    result += func.name;
    return result;
}
