//
// Created by Herman on 22.10.2020.
//

#ifndef CODEGENERATOR_DEPENDENCYMAP_H
#define CODEGENERATOR_DEPENDENCYMAP_H


#include <unordered_map>
#include "../tokens/Object.h"
#include "Dependency.h"

class DependencyMap {
public:
    struct ObjectDeps {
        ObjectDeps(const std::shared_ptr<Object> &obj, Dependency &dep);

        std::shared_ptr<Object> obj;
        Dependency& dep;
    };
    ObjectDeps findClassByName(const std::string & name) ;
    ObjectDeps findFuncByName(const std::string & name) ;
    std::vector<ObjectDeps> findObjectByName(const std::string & name) ;
    void insert(std::shared_ptr<Object> obj, Dependency && dep);
private:
    std::unordered_map<std::shared_ptr<Object>, Dependency> map;
};


#endif //CODEGENERATOR_DEPENDENCYMAP_H
