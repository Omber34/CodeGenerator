//
// Created by Herman on 21.07.2020.
//

#ifndef CODEGENERATOR_CPPFUNCTIONGENERATOR_H
#define CODEGENERATOR_CPPFUNCTIONGENERATOR_H


#include "../generator/FunctionGenerator.h"

class CPPFunctionGenerator : public FunctionGenerator {
public:
    CPPFunctionGenerator();

    std::string generateFunction(const Function &func) override;

private:

    std::string generateBody(const Function &func);

    std::string generateArgumentString(const Function &func);

    std::string generateForwardMods(const Function &func);

    std::string generateBackMods(const Function &func);

    std::string generateArgString(const FunctionArgument &arg);

    std::string generateFullName(const Function& func);
};


#endif //CODEGENERATOR_CPPFUNCTIONGENERATOR_H
