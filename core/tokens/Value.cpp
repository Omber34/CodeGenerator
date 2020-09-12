#include "Value.h"

bool Value::operator==(const Value &rhs) const {
    return type == rhs.type &&
           std::equal(wrappers.begin(), wrappers.end(),  rhs.wrappers.begin(), rhs.wrappers.end());
}

bool Value::operator!=(const Value &rhs) const {
    return !(rhs == *this);
}
