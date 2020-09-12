#include <iostream>
#include "core/parser/JsonParser.h"
#include "core/generator/CPPFunctionGenerator.h"
#include "core/generator/CPPClassGenerator.h"

int main()
{
    std::shared_ptr<FunctionGenerator> funcGenerator = std::make_shared<CPPFunctionGenerator>();
    std::shared_ptr<ClassGenerator> classGenerator = std::make_shared<CPPClassGenerator>();

    JsonParser parser("../tests/examples/schema.json");

    auto schema = parser.getSchema();
    for (auto & obj : schema.objects)
    {
        if (obj->getType() == ObjectType::Function)
        {
            auto func = std::dynamic_pointer_cast<Function>(obj);
            std::cout << funcGenerator->generateFunction(*func) << '\n';
        }
        if (obj->getType() == ObjectType::Class)
        {
            auto func = std::dynamic_pointer_cast<Class>(obj);
            std::cout << classGenerator->generateClass(*func) << '\n';
        }
    }


}