//
// Created by Herman on 16.10.2020.
//

#ifndef CODEGENERATOR_DEPENDENCYRESOLVER_H
#define CODEGENERATOR_DEPENDENCYRESOLVER_H


#include <unordered_map>
#include "../tokens/Schema.h"
#include "Dependency.h"
#include "DependencyMap.h"

class DependencyResolver {
public:
    DependencyResolver(const Schema &tokens);
    DependencyMap resolveDependencyMap();

private:
    Dependency resolveDependencyListForObject(std::shared_ptr<Object> obj) ;
    Dependency resolveDependencyListForFunction(std::shared_ptr<Function> obj) ;
    Dependency resolveDependencyListForClass(std::shared_ptr<Class> obj) ;

private:
    Schema tokens;
    std::unordered_set<ValueType> unresolvedDeps;
    std::unordered_set<ValueType> declTypes;
    DependencyMap dependencyMap;
};


#endif //CODEGENERATOR_DEPENDENCYRESOLVER_H
