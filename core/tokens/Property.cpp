#include "Property.h"

bool Property::operator==(const Property &rhs) const {
    return value == rhs.value &&
           accessLevel == rhs.accessLevel;
}

bool Property::operator!=(const Property &rhs) const {
    return !(rhs == *this);
}
