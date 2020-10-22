//
// Created by Herman on 21.07.2020.
//

#include "CPPHelper.h"

std::string CPPHelper::parseValueType(ValueType vt) {
    return vt;
//    switch (vt) {
//        case ValueType::Integer:
//            return "int";
//        case ValueType::UnsignedInteger:
//            return "unsigned int";
//        case ValueType::String:
//            return "std::string";
//        case ValueType::Bool:
//            return "bool";
//        case ValueType::Float:
//            return "float";
//    }
}

std::string CPPHelper::parseFunctionModifier(FunctionModifier fm) {
    switch (fm) {
        case FunctionModifier::Virtual:
            return "virtual";
        case FunctionModifier::Const:
            return "const";
        case FunctionModifier::PureVirtual:
            return "= 0";
        case FunctionModifier::Static:
            return "static";
    }
}

CPPHelper::CPPHelper() {
    knownDeps = {
            {"std::string", "#include <string>"}
    };
}
