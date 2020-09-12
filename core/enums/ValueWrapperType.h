//
// Created by Herman on 26.07.2020.
//

#ifndef CODEGENERATOR_VALUEWRAPPERTYPE_H
#define CODEGENERATOR_VALUEWRAPPERTYPE_H
#include <string>

enum class ValueWrapperType
{
    ByValue,
    ByReference,
    ByPointer,
};

ValueWrapperType strToValueWrapperType(const std::string &str);
std::string valueWrapperTypeToStr(ValueWrapperType fm);

#endif //CODEGENERATOR_VALUEWRAPPERTYPE_H
