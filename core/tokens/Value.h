#pragma once
#include <string>
#include <vector>
#include "../enums/ValueType.h"
#include "../enums/ValueWrapperType.h"

struct Value
{
    ValueType type;
    std::vector<ValueWrapperType> wrappers;

    bool operator==(const Value &rhs) const;

    bool operator!=(const Value &rhs) const;
};

struct FunctionArgument : public Value
{
    std::string name;
    std::string defaultValue;
};

namespace std{
    template <>
    struct hash<Value>{
        size_t operator()(const Value& func) const{
            auto result = static_cast<size_t>(func.type);
            for (auto wrap : func.wrappers) {
                result ^= static_cast<size_t>(wrap);
            }
            return result;
        }

    };

    template<>
    struct hash<FunctionArgument>{
        size_t operator()(const FunctionArgument& func) const{
            hash<Value> valueHash;
            hash<std::string> stringHash;
            return stringHash(func.name) ^ stringHash(func.defaultValue) ^ valueHash(func);
        }

    };
}