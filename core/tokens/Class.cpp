#include "Class.h"

std::string Class::getName() const {
    return name;
}

ObjectType Class::getType() const {
    return ObjectType::Class;
}

std::vector<ValueType> Class::getAllUsableTypes() const {
    std::vector<ValueType> result;
    for (auto && prop : propertySet)
        result.push_back(prop.value.type);
    for (auto && method : methodSet){
        auto methodTypes = method.getAllUsableTypes();
        result.insert(
                result.end(),
                std::make_move_iterator(methodTypes.begin()),
                std::make_move_iterator(methodTypes.end())
        );
    }
    return result;
}