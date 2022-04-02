#include <iostream>

#include "chapter3.h"

void func() { std::cout << "Modules in C++20" << std::endl; }
const char* OutOfRangeException::what() const throw() {
  return "Index is out of range.";
}
