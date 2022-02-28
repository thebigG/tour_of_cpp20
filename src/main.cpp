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
	Vector_CPP20<float> items{};

	items[0] = 12;

	std::cout<<"first elem:"<<items[0]<< std::endl;

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
