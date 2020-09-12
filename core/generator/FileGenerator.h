//
// Created by Herman on 18.07.2020.
//

#ifndef CODEGENERATOR_FILEGENERATOR_H
#define CODEGENERATOR_FILEGENERATOR_H


#include "CodeGenerator.h"

class FileGenerator : public CodeGenerator {
    std::string filename;
public:
    FileGenerator(std::string const &filename);

    void generateCode(const Schema &schema) override;
};


#endif //CODEGENERATOR_FILEGENERATOR_H
