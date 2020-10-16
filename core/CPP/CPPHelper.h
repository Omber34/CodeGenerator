//
// Created by Herman on 21.07.2020.
//

#ifndef CODEGENERATOR_CPPHELPER_H
#define CODEGENERATOR_CPPHELPER_H


#include "../generator/LanguageHelper.h"
#include <unordered_map>

class CPPHelper : public LanguageHelper {
public:
    CPPHelper();

    std::string parseValueType(ValueType vt) override;

    std::string parseFunctionModifier(FunctionModifier fm) override;

private:
    std::unordered_map<ValueType, std::string> knownDeps;
};


#endif //CODEGENERATOR_CPPHELPER_H
