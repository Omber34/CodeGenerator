//
// Created by Herman on 11/22/2020.
//

#include <gtest/gtest.h>
#include "../core/parser/JsonParser.h"

TEST(FunctionGenerateTest, ParsingFunctionJson) {
    JsonParser parser("../../tests/samples/functions.json");
    auto functions = parser.getSchema();
    auto firstFunc = std::dynamic_pointer_cast<Function>(functions.objects[0]);
    auto secondFunc = std::dynamic_pointer_cast<Function>(functions.objects[1]);

    EXPECT_TRUE(firstFunc);
    EXPECT_TRUE(secondFunc);

    EXPECT_EQ(functions.objects.size(), 2);

    EXPECT_EQ(firstFunc->getType(), ObjectType::Function);
    EXPECT_EQ(secondFunc->getType(), ObjectType::Function);

    EXPECT_STREQ(firstFunc->getName().c_str(), "method1");
    EXPECT_STREQ(secondFunc->getName().c_str(), "method2");
}

TEST(FunctionGenerateTest, FunctionParsing) {
    JsonParser parser("../../tests/samples/functions.json");
    auto functions = parser.getSchema();
    auto firstFunc = std::dynamic_pointer_cast<Function>(functions.objects[0]);
    auto secondFunc = std::dynamic_pointer_cast<Function>(functions.objects[1]);

    EXPECT_TRUE(firstFunc);
    EXPECT_TRUE(secondFunc);

    EXPECT_EQ(firstFunc->arguments.size(), 0);
    EXPECT_STREQ(firstFunc->returnValue.type.c_str(), "String");

    EXPECT_EQ(secondFunc->arguments.size(), 2);
    EXPECT_STREQ(secondFunc->returnValue.type.c_str(), "Integer");

    EXPECT_STREQ(secondFunc->arguments[0].name.c_str(), "first");
    EXPECT_STREQ(secondFunc->arguments[0].type.c_str(), "UnsignedInteger");

    EXPECT_STREQ(secondFunc->arguments[1].name.c_str(), "second");
    EXPECT_STREQ(secondFunc->arguments[1].type.c_str(), "String");

    EXPECT_EQ(firstFunc->modifiers, (std::vector<FunctionModifier>{FunctionModifier::PureVirtual, FunctionModifier::Virtual, FunctionModifier::Const}));
    EXPECT_EQ(secondFunc->modifiers, (std::vector<FunctionModifier>{FunctionModifier::Virtual, FunctionModifier::Const}));
}

TEST(ClassGenerateTest, ParsingClassJson) {
    JsonParser parser("../../tests/samples/schema.json");
    auto functions = parser.getSchema();
    auto firstFunc = std::dynamic_pointer_cast<Function>(functions.objects[0]);
    auto secondFunc = std::dynamic_pointer_cast<Function>(functions.objects[1]);

    EXPECT_TRUE(firstFunc);
    EXPECT_TRUE(secondFunc);

    EXPECT_EQ(functions.objects.size(), 2);

    EXPECT_EQ(firstFunc->getType(), ObjectType::Function);
    EXPECT_EQ(secondFunc->getType(), ObjectType::Function);

    EXPECT_STREQ(firstFunc->getName().c_str(), "method1");
    EXPECT_STREQ(secondFunc->getName().c_str(), "method2");
}