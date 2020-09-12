//
// Created by Herman on 18.07.2020.
//

#include <string>
#include "AccessLevelType.h"
#include "FunctionModifierType.h"
#include "ClassType.h"
#include "ValueType.h"
#include "LanguageType.h"
#include "ValueWrapperType.h"

AccessLevelType strToAccessLevelType(const std::string &str) {
    if (str == "Public"){
        return AccessLevelType::Public;
    } if (str == "Private"){
        return AccessLevelType::Private;
    } if (str == "Protected"){
        return AccessLevelType::Protected;
    }else throw std::logic_error("wrong string access level");
}


FunctionModifier strToFunctionModifier(const std::string &str) {
    if (str == "Virtual"){
        return FunctionModifier::Virtual;
    } if (str == "Const"){
        return FunctionModifier::Const;
    } if (str == "PureVirtual"){
        return FunctionModifier::PureVirtual;
    }if (str == "Static"){
        return FunctionModifier::Static;
    }if (str == "Method"){
        return FunctionModifier::Method;
    }else throw std::logic_error("wrong string function modifier");
}

ClassType strToClassType(const std::string &str) {
    if (str == "Abstract Class"){
        return ClassType::AbstractClass;
    } if (str == "Interface"){
        return ClassType::Interface;
    } if (str == "Class"){
        return ClassType::Class;
    }else throw std::logic_error("wrong string class type");
}

ValueType strToValueType(const std::string &str) {
    if (str == "Integer"){
        return ValueType::Integer;
    } if (str == "UnsignedInteger"){
        return ValueType::UnsignedInteger;
    }if (str == "String"){
        return ValueType::String;
    }if (str == "Bool"){
        return ValueType::Bool;
    }if (str == "Float"){
        return ValueType::Float;
    } else throw std::logic_error("wrong string value type");
}


LanguageType strToLanguageType(const std::string &str)
{
    if (str == "CPP"){
        return LanguageType::CPP;
    } if (str == "Python"){
        return LanguageType::Python;
    }if (str == "Java"){
        return LanguageType::Java;
    } else throw std::logic_error("wrong string language type");
}

ValueWrapperType strToValueWrapperType(const std::string &str){
    if (str == "ByValue"){
        return ValueWrapperType::ByValue;
    } if (str == "ByReference"){
        return ValueWrapperType::ByReference;
    }if (str == "ByPointer"){
        return ValueWrapperType::ByPointer;
    } else throw std::logic_error("wrong string value wrapper type");
}