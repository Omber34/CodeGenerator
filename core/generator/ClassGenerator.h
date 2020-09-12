//
// Created by Herman on 22.07.2020.
//

#ifndef CODEGENERATOR_CLASSGENERATOR_H
#define CODEGENERATOR_CLASSGENERATOR_H


#include <string>
#include "../tokens/Class.h"
#include "LanguageHelper.h"
#include "FunctionGenerator.h"

class ClassGenerator {
public:
    virtual std::string generateClass(Class const& obj) const = 0;

protected:
    std::shared_ptr<LanguageHelper> language;
    std::shared_ptr<FunctionGenerator> functionGenerator;
    std::string classPattern;
};


#endif //CODEGENERATOR_CLASSGENERATOR_H
