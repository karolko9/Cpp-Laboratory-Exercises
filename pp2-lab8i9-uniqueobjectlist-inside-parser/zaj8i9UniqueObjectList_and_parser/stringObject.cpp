#include <iostream>
#include <random>
#include <typeinfo>
#include <type_traits>
#include <cstring>
#include <cctype>
#include "stringObject.h"
using namespace std;

// TODO:
bool StringObject::operator==(const Object &obj) const {
    StringObject* temp = (StringObject*) &obj;
    return text == temp->text;
}
