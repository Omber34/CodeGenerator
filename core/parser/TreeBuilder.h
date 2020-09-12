//
// Created by Herman on 17.07.2020.
//

#ifndef CODE_GENERATOR_TREEBUILDER_H
#define CODE_GENERATOR_TREEBUILDER_H

#include "../tokens/Schema.h"

class TreeBuilder {
public:
    virtual Schema getSchema() const =0;
};


#endif //CODE_GENERATOR_TREEBUILDER_H
