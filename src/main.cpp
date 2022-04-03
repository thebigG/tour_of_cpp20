#include <iostream>
#include <string>
#include <utility>
#include <variant>
#include <vector>

#include "chapter2.h"
#include "chapter3.h"
#include "chapter4.h"

int main() {
  // Chapter 2 tests
  Object a{200};
  VarObject obj{a};
  Vector_CPP20<double> items{4,  8, 16, 4,  8, 16, 4,  8,
                             16, 4, 8,  16, 4, 8,  16, 7};

  // items.pushBack(15.1);
  std::cout << "front of vector:" << items.front() << std::endl;

  if (std::holds_alternative<Object>(obj.var)) {
    std::cout << "Value of obj0:" << std::get<Object>(obj.var) << std::endl;
  }

  else if (std::holds_alternative<int>(obj.var)) {
    std::cout << "Value of obj1:" << std::get<int>(obj.var) << std::endl;
  }

  std::visit(
      [](auto&& var) { std::cout << "visit variant:" << var << std::endl; },
      obj.var);
  std::cout << "Value of obj2:" << a << std::endl;
  return 0;
}
