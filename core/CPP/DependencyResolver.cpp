//
// Created by Herman on 16.10.2020.
//

#include "DependencyResolver.h"

DependencyResolver::DependencyResolver(const Schema &tokens)
    : tokens(tokens)
{
    declTypes = this->tokens.getAllDeclareTypes();
}

Dependency DependencyResolver::resolveDependencyListForObject(std::shared_ptr<Object> obj)  {
    if (auto it = std::dynamic_pointer_cast<Function>(obj))
        return resolveDependencyListForFunction(it);
    if (auto it = std::dynamic_pointer_cast<Class>(obj))
        return resolveDependencyListForClass(it);
    return Dependency();
}

Dependency DependencyResolver::resolveDependencyListForFunction(std::shared_ptr<Function> obj)  {
    Dependency result;
    for (auto && type: obj->getAllUsableTypes())
    {
        if (declTypes.find(type) != declTypes.end())
            result.imports.push_back(type);
        else
            result.unresolved.push_back(type);
    }
    return result;
}

Dependency DependencyResolver::resolveDependencyListForClass(std::shared_ptr<Class> obj)  {
    Dependency result;

    for (auto && type: obj->getAllUsableTypes())
    {
        if (declTypes.find(type) != declTypes.end()){
            auto thisDep = dependencyMap.findClassByName(type);
            auto importsDep = thisDep.dep.imports;
            if (std::find(importsDep.begin(), importsDep.end(), obj->name) != importsDep.end()){
                //TODO: after make functions body parsing deduce who is maintainer and make actual forwarDecl-include pairs
                thisDep.dep.forwardDecl.push_back(type);
                result.forwardDecl.push_back(thisDep.obj->getName());
            }
            else {
                result.imports.push_back(type);
            }
        }
        else
            result.unresolved.push_back(type);
    }

    return result;
}
