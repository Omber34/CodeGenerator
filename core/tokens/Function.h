#pragma once
#include <vector>
#include "Value.h"
#include "../enums/FunctionModifierType.h"
#include "Object.h"

struct Function : public Object
{
    Value returnValue;

    ObjectType getType() const override;

    std::string getName() const override;

    std::vector<FunctionArgument> arguments;
    std::string name;
    std::vector<FunctionModifier> modifiers;

    std::weak_ptr<Object> owner;

    bool operator==(const Function &rhs) const;

    bool operator!=(const Function &rhs) const;
};

namespace std{
    template <>
    struct hash<Function>{
        size_t operator()(const Function& func) const{
            hash<std::string> strh;
            hash<Value> valh;
            auto name_h = strh(func.name);
            for (auto & arg : func.arguments)
            {
                name_h ^= valh(arg);
            }
            name_h ^= valh(func.returnValue);
            return name_h;
        }

    };
}