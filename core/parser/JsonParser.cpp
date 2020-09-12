//
// Created by Herman on 17.07.2020.
//
#include <fstream>
#include <unordered_set>
#include "JsonParser.h"
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"

std::shared_ptr<Object> parseClass(const rapidjson::Value &value);

Value parseValue(rapidjson::Value const & object)
{
    Value result;
    result.type = strToValueType(object["type"].GetString());
    auto wrappers = object["wrappers"].GetArray();
    for (rapidjson::SizeType i = 0; i < wrappers.Size(); ++i)
        result.wrappers.push_back(strToValueWrapperType(wrappers[i].GetString()));
    return result;
}

FunctionArgument parseFunctionArgument(const rapidjson::Value & object)
{
    FunctionArgument result;
    result.type = strToValueType(object["type"].GetString());
    auto wrappers = object["wrappers"].GetArray();
    for (rapidjson::SizeType i = 0; i < wrappers.Size(); ++i)
        result.wrappers.push_back(strToValueWrapperType(wrappers[i].GetString()));

    if (object.HasMember("defaultValue"))
        result.defaultValue = object["defaultValue"].GetString();

    result.name = object["name"].GetString();
    return result;
}

Property parseProperty(const rapidjson::Value & object)
{
    Property result;
    result.value = parseValue(object["value"]);
    result.name = object["name"].GetString();
    result.accessLevel = strToAccessLevelType(object["accessLevel"].GetString());
    return result;
}

Function parseFunction(const rapidjson::Value & object)
{
    Function result;
    result.returnValue = parseValue(object["return"]);
    result.name = object["name"].GetString();

    auto args = object["arguments"].GetArray();
    for (rapidjson::SizeType i = 0; i < args.Size(); ++i)
        result.arguments.push_back(parseFunctionArgument(args[i]));

    auto modifiers = object["modifiers"].GetArray();
    for (rapidjson::SizeType i = 0; i < modifiers.Size(); ++i)
        result.modifiers.push_back(strToFunctionModifier(modifiers[i].GetString()));

    if (std::find(result.modifiers.begin(), result.modifiers.end(), FunctionModifier::Method) != result.modifiers.end())
        result.accessLevel = strToAccessLevelType(object["accessLevel"].GetString());

    return result;
}

std::unordered_set<Function> parseMethods(const rapidjson::Value & object){
    std::unordered_set<Function> result;
    for (rapidjson::SizeType i = 0; i < object.Size(); ++i)
    {
        result.emplace(parseFunction(object[i]));
    }
    return result;
}

std::unordered_set<Property> parseProperties(const rapidjson::Value & object){
    std::unordered_set<Property> result;
    for (rapidjson::SizeType i = 0; i < object.Size(); ++i)
    {
        result.emplace(parseProperty( object[i]));
    }
    return result;
}

std::shared_ptr<Object> parseObject(const rapidjson::Value & object){
    std::shared_ptr<Object> result;
    if (object["objectType"].GetString() == std::string("Class") ||
            object["objectType"].GetString() == std::string("Interface")||
            object["objectType"].GetString() == std::string("Abstract Class")) {
        result = parseClass(object);
    }
    if (object["objectType"].GetString() == std::string("Function"))
    {
        std::shared_ptr<Function> func = std::make_shared<Function>();
        (*func) = parseFunction(object);
        result = func;
    }
    return result;
}

std::shared_ptr<Object> parseClass(const rapidjson::Value &value) {
    std::shared_ptr<Class> result = std::make_shared<Class>();
    result->name = value["name"].GetString();
    result->type = strToClassType(value["objectType"].GetString());
    result->methodSet = parseMethods(value["methods"]);
    result->propertySet = parseProperties(value["properties"]);
    return result;
}

Schema JsonParser::getSchema() const {
    return currentSchema;
}

JsonParser::JsonParser(const std::string& filename) {
    rapidjson::Document json;
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::logic_error("cannot find file");
    rapidjson::IStreamWrapper jsonFile(file);
    if (!json.ParseStream(jsonFile).IsArray())
        throw std::logic_error("wrong json format");

    for (rapidjson::SizeType i = 0; i < json.Size(); ++i)
       currentSchema.objects.push_back(parseObject( json[i].GetObject()));

}


