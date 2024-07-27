#pragma once

#include <iosfwd>
#include <string>
#include "object.h"


class StringObject : public Object
{
    std::string text;

public:    
//     TODO:
    StringObject(std::string s) : text(s) {};



    bool operator==(const Object& obj) const override;

    Object* clone() const override
    {
       return new StringObject(*this);
    }








};
