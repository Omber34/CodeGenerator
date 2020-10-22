#pragma once 
#include <string>

//enum class ValueType {
//    Integer,
//    UnsignedInteger,
//    String,
//    Bool,
//    Float,
//
//};

using ValueType = std::string;

ValueType strToValueType(const std::string &str);
std::string valueTypeToStr(ValueType fm);
