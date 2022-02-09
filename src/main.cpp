module;

#include <iostream>
#include <variant>
#include <string>
#include <utility>
#include "chapter2.h"


#include <iostream>

//import iostream
//export module Chapter3;

//void func()
//{
//	std::cout<<"Modules in C++20"<<std::endl;
//}

//import Chapter3;

int main()
{
	// Chapter 2 tests
	Object a{200};
	VarObject obj{a};

	if (std::holds_alternative<Object>(obj.var))
	{
		std::cout<<"Value of obj0:" << std::get<Object>(obj.var) <<std::endl;
	}

	else if(std::holds_alternative<int>(obj.var))
	{
		std::cout<<"Value of obj1:" << std::get<int>(obj.var) <<std::endl;
	}

	std::visit([](auto&& var){std::cout<<"visit variant:"<<var<<std::endl;}, obj.var);
	std::cout<<"Value of obj2:" << a <<std::endl;
	return 0;
}
