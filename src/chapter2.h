#ifndef CHAPTER2_H
#define CHAPTER2_H

#include <iostream>
#include <variant>
#include <string>
#include <utility>

class Object
{
public:
	int objId = 0;
	Object(int newId);
	Object(Object& newObj);
};

class VarObject
{
public:
	VarObject(int newVarVal);
	VarObject(Object newVarVal);
	int num;
	std::variant<Object, int> var;
};

std::basic_ostream<char>& operator<<(std::basic_ostream<char, std::char_traits<char>>& __out, const Object& __s);

#endif // CHAPTER2_H
