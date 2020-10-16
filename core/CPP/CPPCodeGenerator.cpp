//
// Created by Herman on 17.10.2020.
//

#include "CPPCodeGenerator.h"

void CPPCodeGenerator::generateCode(const Schema &schema) {

}

CPPCodeGenerator::CPPCodeGenerator(const Schema &tokens)
    : tokens(tokens) {}

void CPPCodeGenerator::resolveFileList() {
    for (auto && symbol : tokens.objects)
    {
        fileList.push_back(symbol->getName() + ".h");
        fileList.push_back(symbol->getName() + ".cpp");
    }
}

void CPPCodeGenerator::resolveDependency() {

}

void CPPCodeGenerator::generate() {

}
