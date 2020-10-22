//
// Created by Herman on 17.10.2020.
//

#include "CPPCodeGenerator.h"

void CPPCodeGenerator::generateCode(const Schema &schema) {

}

CPPCodeGenerator::CPPCodeGenerator(const Schema &tokens)
    : tokens(tokens), dependencyResolver(std::make_unique<DependencyResolver>(tokens))
{

}

void CPPCodeGenerator::resolveFileList() {
    bool hasStaticFunctions = false;
    for (auto && symbol : tokens.objects)
    {
        if (auto class_ = std::dynamic_pointer_cast<Class>(symbol)) {
            fileList.push_back(class_->getName() + ".h");
            fileList.push_back(class_->getName() + ".cpp");
        }
        if (auto func = std::dynamic_pointer_cast<Function>(symbol)) {
            auto funcMods = func->modifiers;
            if (std::find(funcMods.begin(), funcMods.end(), FunctionModifier::Static) != funcMods.end())
                hasStaticFunctions = true;
        }
    }
    if (hasStaticFunctions)
    {
        fileList.emplace_back("StaticFunctions.h");
    }
}

void CPPCodeGenerator::resolveDependency() {

}

void CPPCodeGenerator::generate() {

}
