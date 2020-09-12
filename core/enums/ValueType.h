#pragma once 
#include <string>

enum class ValueType {
    Integer,
    UnsignedInteger,
    String,
    Bool,
    Float,
    
};

ValueType strToValueType(const std::string &str);
std::string valueTypeToStr(ValueType fm);
