//
// Created by Herman on 17.07.2020.
//

#ifndef CODEGENERATOR_SCHEMA_H
#define CODEGENERATOR_SCHEMA_H


#include <vector>
#include "Class.h"

struct Schema {
    std::vector<std::shared_ptr<Object>> objects;
};


#endif //CODEGENERATOR_SCHEMA_H
