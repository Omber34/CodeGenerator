//
// Created by Herman on 22.07.2020.
//

#ifndef CODEGENERATOR_CPPCLASSGENERATOR_H
#define CODEGENERATOR_CPPCLASSGENERATOR_H


#include "ClassGenerator.h"

class CPPClassGenerator : public ClassGenerator {
public:
    CPPClassGenerator();

    std::string generateClass(const Class &obj) const override;

private:

    std::string generateFullName(const Class& obj) const;

    std::string generateBody(const Class& obj) const;
    std::string generatePrivate(const Class& obj) const;
    std::string generateProtected(const Class& obj) const;
    std::string generatePublic(const Class& obj) const;

    std::string generateAccessType(const Class &obj, AccessLevelType accessType) const;

    std::string generateProperty(const Property& prop) const;

    std::string classBodyPattern;
    std::string classPropertyPattern;
    std::string methodPattern;
    std::string propertyPattern;
};


#endif //CODEGENERATOR_CPPCLASSGENERATOR_H
