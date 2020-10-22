//
// Created by Herman on 22.07.2020.
//

#include <fmt/format.h>
#include "CPPClassGenerator.h"
#include "CPPHelper.h"
#include "CPPFunctionGenerator.h"

std::string CPPClassGenerator::generateClass(const Class &obj) const {
    std::string result;
    result = fmt::format(classPattern,
                        generateFullName(obj),
                        generateBody(obj));
    return result;
}

CPPClassGenerator::CPPClassGenerator() {
    classPattern = "class {0} {1}";
    classBodyPattern = "{{\npublic:\n{0}\nprotected:\n{1}\nprivate:\n{2}\n}}";
    classPropertyPattern = "\n{0}";
    propertyPattern = "{0} {1};\n";
    methodPattern = "\n{0}\n";
    language = std::make_shared<CPPHelper>();
    functionGenerator = std::make_shared<CPPFunctionGenerator>();
}

std::string CPPClassGenerator::generateFullName(const Class &obj) const {
    std::string result ;
    if (!obj.owner.expired())
    {
        result = obj.owner.lock()->getName() + "::";
    }
    result += obj.name;
    return result;
}

std::string CPPClassGenerator::generateBody(const Class &obj) const {
    std::string result;
    result = fmt::format(classBodyPattern,
                         generatePublic(obj),
                         generateProtected(obj),
                         generatePrivate(obj));
    return result;
}

std::string CPPClassGenerator::generatePrivate(const Class &obj) const {
    return generateAccessType(obj, AccessLevelType::Private);
}

std::string CPPClassGenerator::generateProtected(const Class &obj) const {
    return generateAccessType(obj, AccessLevelType::Protected);
}

std::string CPPClassGenerator::generatePublic(const Class &obj) const {
    return generateAccessType(obj, AccessLevelType::Public);
}

std::string CPPClassGenerator::generateProperty(const Property &prop) const {
    return fmt::format(propertyPattern, prop.value.type, prop.name);
}

std::string CPPClassGenerator::generateAccessType(const Class &obj, AccessLevelType accessType) const {
    std::string result;
    for (auto & func : obj.methodSet) {
        if (func.accessLevel == accessType)
            result += fmt::format(methodPattern, functionGenerator->generateFunction(func));
    }

    for (auto & prop : obj.propertySet) {
        if (prop.accessLevel == accessType)
            result += fmt::format(classPropertyPattern, generateProperty(prop));
    }
    return result;
}
