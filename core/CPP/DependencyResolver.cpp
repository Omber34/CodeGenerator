//
// Created by Herman on 16.10.2020.
//

#include "DependencyResolver.h"

DependencyResolver::DependencyResolver(const Schema &tokens) : tokens(tokens) {}

std::string DependencyResolver::resolveDependencyListForObject(std::shared_ptr<Object> obj) const {
    if (auto it = std::dynamic_pointer_cast<Function>(obj))
        return resolveDependencyListForFunction(it);
    if (auto it = std::dynamic_pointer_cast<Class>(obj))
        return resolveDependencyListForClass(it);
}

std::string DependencyResolver::resolveDependencyListForFunction(std::shared_ptr<Function> obj) const {
    return std::string();
}

std::string DependencyResolver::resolveDependencyListForClass(std::shared_ptr<Class> obj) const {
    return std::string();
}
