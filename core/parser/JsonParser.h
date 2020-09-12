//
// Created by Herman on 17.07.2020.
//

#ifndef CODEGENERATOR_JSONPARSER_H
#define CODEGENERATOR_JSONPARSER_H


#include "TreeBuilder.h"

class JsonParser : public TreeBuilder {
    Schema currentSchema;

public:
    JsonParser(const std::string& );

    Schema getSchema() const override;

};


#endif //CODEGENERATOR_JSONPARSER_H
