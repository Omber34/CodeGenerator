#pragma once


#include <unordered_set>
#include "Property.h"
#include "Function.h"
#include "../enums/ClassType.h"
#include "Object.h"

struct Class : public Object
{
    ObjectType getType() const override;

    std::string name;
    ClassType type;
    std::unordered_set<Property> propertySet;
    std::unordered_set<Function> methodSet;

    std::weak_ptr<Object> owner;

    std::string getName() const override;

    std::unordered_set<std::string> getAllDeclareTypes() const override;

    std::unordered_set<ValueType> getAllUsableTypes() const override;
};