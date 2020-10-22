//
// Created by Herman on 17.07.2020.
//

#include "Schema.h"
#include <algorithm>
#include <iterator>

std::unordered_set<ValueType> Schema::getAllDeclareTypes() {
    std::unordered_set<ValueType> result;
    auto inserter = std::inserter(result, result.end());
    for (auto obj : objects) {
        auto currDeclTypes = obj->getAllDeclareTypes();
        std::copy(
                std::make_move_iterator(currDeclTypes.begin()),
                std::make_move_iterator(currDeclTypes.end()),
                inserter
                );
    }

    return result;
}
