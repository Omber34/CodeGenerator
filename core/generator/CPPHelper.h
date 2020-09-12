//
// Created by Herman on 21.07.2020.
//

#ifndef CODEGENERATOR_CPPHELPER_H
#define CODEGENERATOR_CPPHELPER_H


#include "LanguageHelper.h"

class CPPHelper : public LanguageHelper {
public:
    std::string parseValueType(ValueType vt) override;

    std::string parseFunctionModifier(FunctionModifier fm) override;
};


#endif //CODEGENERATOR_CPPHELPER_H
