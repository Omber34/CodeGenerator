//
// Created by Herman on 17.10.2020.
//

#ifndef CODEGENERATOR_CPPCODEGENERATOR_H
#define CODEGENERATOR_CPPCODEGENERATOR_H


#include "../generator/CodeGenerator.h"
#include "../generator/FileGenerator.h"
#include "DependencyResolver.h"
#include <memory>

class CPPCodeGenerator : public CodeGenerator {
public:
    CPPCodeGenerator(const Schema &tokens);

    void generateCode(const Schema &schema) override;

private:
    void resolveFileList();
    void resolveDependency();
    void generate();

private:
    std::unique_ptr<FileGenerator> fileGenerator;
    std::unique_ptr<DependencyResolver> dependencyResolver;
    std::vector<std::string> fileList;
    Schema tokens;
};


#endif //CODEGENERATOR_CPPCODEGENERATOR_H
