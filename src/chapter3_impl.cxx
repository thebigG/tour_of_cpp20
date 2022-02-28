module;
#include <iostream>
module Chapter3;
void func()
{
	std::cout<<"Modules in C++20"<<std::endl;
}
template <typename T>
MyVector<T>::MyVector()
{
elements = new T[MIN_SIZE];
}

