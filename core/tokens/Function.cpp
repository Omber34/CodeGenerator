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

std::vector<ValueType> Function::getAllUsableTypes() const {
    std::vector<ValueType> result;
    result.push_back(returnValue.type);
    for (auto && arg : arguments)
        result.push_back(arg.type);
    return result;
}
