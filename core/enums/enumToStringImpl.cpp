//
// Created by Herman on 21.07.2020.
//
#include "AccessLevelType.h"
#include "FunctionModifierType.h"
#include "ClassType.h"
#include "ValueType.h"
#include "LanguageType.h"
#include "ValueWrapperType.h"

std::string accessLevelTypeToStr(AccessLevelType alt)
{
    switch (alt) {
        case AccessLevelType::Public:
            return "Public";
        case AccessLevelType::Private:
            return "Private";
        case AccessLevelType::Protected:
            return "Protected";
    }
}

std::string functionModifierToStr(FunctionModifier fm)
{
    switch (fm) {
        case FunctionModifier::Virtual:
            return "Virtual";
        case FunctionModifier::Const:
            return "Const";
        case FunctionModifier::PureVirtual:
            return "PureVirtual";
        case FunctionModifier::Static:
            return "Static";
        case FunctionModifier::Method:
            return "Method";
    }
}

std::string classTypeToStr(ClassType fm)
{
    switch (fm) {
        case ClassType::Class:
            return "Class";
        case ClassType::AbstractClass:
            return "AbstractClass";
        case ClassType::Interface:
            return "Interface";
    }
}

std::string valueTypeToStr(ValueType fm)
{
    switch (fm) {
        case ValueType::Integer:
            return "Integer";
        case ValueType::UnsignedInteger:
            return "UnsignedInteger";
        case ValueType::String:
            return "String";
        case ValueType::Bool:
            return "Bool";
        case ValueType::Float:
            return "Float";
    }
}

std::string languageTypeToStr(LanguageType fm)
{
    switch (fm) {
        case LanguageType::CPP:
            return "CPP";
        case LanguageType::Python:
            return "Python";
        case LanguageType::Java:
            return "Java";
    }
}

std::string valueWrapperTypeToStr(ValueWrapperType fm)
{
    switch (fm) {
        case ValueWrapperType::ByValue:
            return "ByValue";
        case ValueWrapperType::ByReference:
            return "ByReference";
        case ValueWrapperType::ByPointer:
            return "ByPointer";
    }
}