#include "Function.h"

bool Function::operator==(const Function &rhs) const {
    return returnValue == rhs.returnValue &&
           arguments == rhs.arguments &&
           name == rhs.name &&
           modifiers == rhs.modifiers &&
           !owner.expired() && !rhs.owner.expired() &&
           owner.lock() == rhs.owner.lock();
}

bool Function::operator!=(const Function &rhs) const {
    return !(rhs == *this);
}

std::string Function::getName() const {
    return name;
}

ObjectType Function::getType() const {
    return ObjectType::Function;
}

std::unordered_set<ValueType> Function::getAllUsableTypes() const {
    std::unordered_set<ValueType> result;
    result.insert(returnValue.type);
    for (auto && arg : arguments)
        result.insert(arg.type);
    return result;
}

std::unordered_set<std::string> Function::getAllDeclareTypes() const {
    return std::unordered_set<std::string>();
}
