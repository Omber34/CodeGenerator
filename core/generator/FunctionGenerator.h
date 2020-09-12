//
// Created by Herman on 21.07.2020.
//

#ifndef CODEGENERATOR_FUNCTIONGENERATOR_H
#define CODEGENERATOR_FUNCTIONGENERATOR_H


#include "../tokens/Function.h"
#include "LanguageHelper.h"
#include "../enums/LanguageType.h"

class FunctionGenerator {
public:

    virtual std::string generateFunction(const Function& func) =0;

protected:
    std::shared_ptr<LanguageHelper> language;
    std::string functionPattern;
};


#endif //CODEGENERATOR_FUNCTIONGENERATOR_H
