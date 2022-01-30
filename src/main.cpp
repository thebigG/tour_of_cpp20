#include <iostream>
#include <variant>
#include <string>
#include <utility>
#include "chapter2.h"

int main()
{
	// Chapter 2 tests
	Object a{100};
	VarObject obj{a};
	std::cout << "Hello World!" << std::endl;
	std::cout<<"Value of obj1:" << std::get<Object>(obj.var) <<std::endl;
	std::cout<<"Value of obj2:" << a <<std::endl;
	return 0;
}
