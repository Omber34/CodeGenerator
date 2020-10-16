//
// Created by Herman on 16.10.2020.
//

#ifndef CODEGENERATOR_DEPENDENCYRESOLVER_H
#define CODEGENERATOR_DEPENDENCYRESOLVER_H


#include "../tokens/Schema.h"

class DependencyResolver {
public:
    DependencyResolver(const Schema &tokens);
    std::string resolveDependencyListForObject(std::shared_ptr<Object> obj) const;

private:
    std::string resolveDependencyListForFunction(std::shared_ptr<Function> obj) const;
    std::string resolveDependencyListForClass(std::shared_ptr<Class> obj) const;

private:
    Schema tokens;
};


#endif //CODEGENERATOR_DEPENDENCYRESOLVER_H
