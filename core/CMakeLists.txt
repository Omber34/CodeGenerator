cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

set(SRC
        tokens/Class.h
        tokens/Class.cpp
        tokens/Property.h
        tokens/Property.cpp
        tokens/Value.h
        tokens/Value.cpp
        tokens/Function.h
        tokens/Function.cpp
        parser/TreeBuilder.h
        tokens/Schema.cpp
        tokens/Schema.h
        parser/JsonParser.cpp
        parser/JsonParser.h
        enums/ClassType.h
        enums/ValueType.h
        enums/AccessLevelType.h
        enums/FunctionModifierType.h
        enums/StrToEnumImpl.cpp
        enums/enumToStringImpl.cpp
        generator/CodeGenerator.h
        generator/FileGenerator.cpp
        generator/FileGenerator.h
        generator/FunctionGenerator.h

        generator/LanguageHelper.h
        CPP/CPPHelper.cpp
        CPP/CPPHelper.h
        CPP/CPPFunctionGenerator.cpp
        CPP/CPPFunctionGenerator.h
        enums/LanguageType.h
        tokens/Namespace.h
        tokens/Object.h
        enums/ObjectType.h
        generator/ClassGenerator.h
        CPP/CPPClassGenerator.cpp
        CPP/CPPClassGenerator.h
        enums/ValueWrapperType.h
        CPP/DependencyResolver.cpp
        CPP/DependencyResolver.h
        CPP/CPPCodeGenerator.cpp
        CPP/CPPCodeGenerator.h
        tokens/Object.cpp
        CPP/Dependency.cpp
        CPP/Dependency.h
        CPP/DependencyMap.cpp
        CPP/DependencyMap.h)

add_library(core ${SRC})

target_link_libraries(core PUBLIC modules)