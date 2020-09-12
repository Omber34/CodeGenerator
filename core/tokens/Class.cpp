#include "Class.h"

std::string Class::getName() const {
    return name;
}

ObjectType Class::getType() const {
    return ObjectType::Class;
}
