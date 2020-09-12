//
// Created by Herman on 17.07.2020.
//

#ifndef CODEGENERATOR_CLASSTYPE_H
#define CODEGENERATOR_CLASSTYPE_H

#include <string>

enum class ClassType{
    Class,
    AbstractClass,
    Interface
};

ClassType strToClassType(const std::string &str);
std::string classTypeToStr(ClassType fm);

#endif //CODEGENERATOR_CLASSTYPE_H
