//
// Created by Herman on 21.10.2020.
//

#ifndef CODEGENERATOR_DEPENDENCY_H
#define CODEGENERATOR_DEPENDENCY_H


#include "../tokens/Object.h"
#include "../enums/ValueType.h"

struct Dependency {
    std::vector<ValueType> imports;
    std::vector<ValueType> forwardDecl;
    std::vector<ValueType> unresolved;
};


#endif //CODEGENERATOR_DEPENDENCY_H
