//
// Created by Herman on 18.07.2020.
//

#ifndef CODEGENERATOR_CODEGENERATOR_H
#define CODEGENERATOR_CODEGENERATOR_H


#include "../tokens/Schema.h"

class CodeGenerator {
public:
    virtual void generateCode(Schema const& schema) = 0;
};


#endif //CODEGENERATOR_CODEGENERATOR_H
