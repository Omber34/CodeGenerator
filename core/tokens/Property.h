#pragma once
#include "Value.h"
#include "../enums/AccessLevelType.h"

struct Property
{
    Value value;
    std::string name;
    AccessLevelType accessLevel;

    bool operator==(const Property &rhs) const;

    bool operator!=(const Property &rhs) const;
};

namespace std{
    template <>
    struct hash<Property>{
        size_t operator()(const Property& prop)const {
            hash<Value> valueHash;
            hash<string> stringHash;
            return valueHash(prop.value) ^ static_cast<int>(prop.accessLevel) ^ stringHash(prop.name);
        }

    };
}