//
// Created by Herman on 21.07.2020.
//

#ifndef CODEGENERATOR_NAMESPACE_H
#define CODEGENERATOR_NAMESPACE_H

#include "Object.h"

struct Namespace : public Object
{
    std::string getName() const override {
        return name;
    }

    ObjectType getType() const override {
        return ObjectType::Namespace;
    }

    std::string name;
};

#endif //CODEGENERATOR_NAMESPACE_H
