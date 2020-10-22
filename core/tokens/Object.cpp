//
// Created by Herman on 21.10.2020.
//

#include "Object.h"
#include "../enums/ValueType.h"
#include <iterator>

std::unordered_set<std::string> Object::getAllTypes() const {
    std::unordered_set<ValueType> result = getAllUsableTypes();
    std::unordered_set<ValueType> declTypes = getAllDeclareTypes();

    auto inserter = std::inserter(result, result.end());

    std::copy(
            std::make_move_iterator(declTypes.begin()),
            std::make_move_iterator(declTypes.end()),
            inserter
    );

    return result;
}

