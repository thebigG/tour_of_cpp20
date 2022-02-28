#include <iostream>
#include <variant>
#include <string>
#include <utility>
#include <iostream>

import Chapter3;
import Chapter2;

int main()
{
	// Chapter 2 tests
	Object a{200};
	VarObject obj{a};

	func();
//	MyVector<int> items{};

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
