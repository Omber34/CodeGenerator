//
// Created by Herman on 21.07.2020.
//

#ifndef CODEGENERATOR_OBJECT_H
#define CODEGENERATOR_OBJECT_H

#include <string>
#include "../enums/ObjectType.h"
#include "../enums/AccessLevelType.h"

struct Object {
public:
    virtual std::string getName() const = 0;
    virtual ObjectType getType() const = 0;
    AccessLevelType accessLevel;
};

#endif //CODEGENERATOR_OBJECT_H
