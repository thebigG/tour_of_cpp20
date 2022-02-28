module;
#include <iostream>
export module Chapter3;

export void func();
export template <typename T>
class Vector_CPP20{

public:
	//Implementations are defined here because I can't figure out a way
	//at the moment how to separate the interface from implementation in GCC 11.2
	//when working with templates and modules.
	Vector_CPP20()
	{
	elements = new T[MIN_SIZE];
	}
	~Vector_CPP20 ()
	{
		delete[] elements;
	}

	T& operator [](int i)
	{
		return elements[i];
	}
private:
	T* elements;
	const int MIN_SIZE = 16;
};

void func()
{
	std::cout<<"Modules in C++20"<<std::endl;
}
