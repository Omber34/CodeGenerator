//
// Created by Herman on 21.07.2020.
//

#ifndef CODEGENERATOR_LANGUAGEHELPER_H
#define CODEGENERATOR_LANGUAGEHELPER_H


#include <string>
#include "../enums/ValueType.h"
#include "../enums/FunctionModifierType.h"

class LanguageHelper {
public:
    virtual std::string parseValueType(ValueType vt) =0;
    virtual std::string parseFunctionModifier(FunctionModifier fm) =0;

};


#endif //CODEGENERATOR_LANGUAGEHELPER_H
