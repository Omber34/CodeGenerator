//
// Created by Herman on 22.10.2020.
//

#include "DependencyMap.h"
#include "../tokens/Class.h"
#include <algorithm>
#include <utility>

DependencyMap::ObjectDeps DependencyMap::findClassByName(const std::string &name)  {
    auto it = std::find_if(map.begin(), map.end(),
            [&name] (auto it) {
                if (auto class_ = std::dynamic_pointer_cast<Class>(it.first)){
                    return class_->name == name;
                }
                else
                    return false;
    });
    return ObjectDeps(it->first, it->second);
}

DependencyMap::ObjectDeps DependencyMap::findFuncByName(const std::string &name)  {
    auto it =  std::find_if(map.begin(), map.end(),
                        [&name] (auto it) {
                            if (auto func = std::dynamic_pointer_cast<Function>(it.first)){
                                return func->name == name;
                            }
                            else
                                return false;
                        });
    return ObjectDeps(it->first, it->second);
}

std::vector<DependencyMap::ObjectDeps> DependencyMap::findObjectByName(const std::string &name)  {
    std::vector<DependencyMap::ObjectDeps> result;
    auto inserter = std::back_inserter(result);

    for (auto&& it : map){
        if (auto func = std::dynamic_pointer_cast<Function>(it.first)){
            if (func->name == name)
                inserter = ObjectDeps(it.first, it.second);
        }
        if (auto class_ = std::dynamic_pointer_cast<Class>(it.first)){
            if (class_->name == name)
                inserter = ObjectDeps(it.first, it.second);
        }
    }
    return result;
}

void DependencyMap::insert(std::shared_ptr<Object> obj, Dependency &&dep) {
    map.emplace(obj, std::move(dep));
}

DependencyMap::ObjectDeps::ObjectDeps(const std::shared_ptr<Object> &obj, Dependency &dep) : obj(obj), dep(dep) {}
