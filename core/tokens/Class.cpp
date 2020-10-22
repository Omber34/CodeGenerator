#include "Class.h"
#include <iterator>

std::string Class::getName() const {
    return name;
}

ObjectType Class::getType() const {
    return ObjectType::Class;
}

std::unordered_set<ValueType> Class::getAllUsableTypes() const {
    std::unordered_set<ValueType> result;
    auto inserter = std::inserter(result, result.end());
    for (auto && prop : propertySet)
        inserter = prop.value.type;
    for (auto && method : methodSet){
        auto methodTypes = method.getAllUsableTypes();
        std::copy(
                std::make_move_iterator(methodTypes.begin()),
                std::make_move_iterator(methodTypes.end()),
                inserter
        );
    }
    return result;
}

std::unordered_set<std::string> Class::getAllDeclareTypes() const {
    return std::unordered_set<std::string>({ {name}} );
}
