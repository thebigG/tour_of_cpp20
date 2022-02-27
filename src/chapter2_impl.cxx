module;
//Any includes you want go here
#include <variant>
#include <iostream>
module Chapter2;
std::basic_ostream<char>& operator<<(std::basic_ostream<char, std::char_traits<char>>& __out, const Object& __s)
{
   std::string value{std::to_string(__s.objId)};
   __out.write(value.c_str(), value.size());
   return __out;
}

Object::Object(int newId): objId{newId}
{
}

VarObject::VarObject(int newVarVal): var{newVarVal}
{

}

VarObject::VarObject(Object newVarVal): var{newVarVal}
{

}

Object::Object(Object& newObj): objId{newObj.objId}
{

}

