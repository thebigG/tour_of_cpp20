#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>
#include <utility>
#include <variant>
#include <vector>

#include "chapter2.h"
#include "chapter3.h"
#include "chapter4.h"
#include "chapter5.h"

TEST_CASE("1: All test cases reside in other .cpp files (empty)",
          "[multi-file:1]") {}

TEST_CASE("Factorial of 0 is 1 (fail)", "[single-file]") {
  Object a{200};
  VarObject obj{a};
  Vector_CPP20<double> items{4,  8, 16, 4,  8, 16, 4,  8,
                             16, 4, 8,  16, 4, 8,  16, 7};

  // items.pushBack(15.1);
  std::cout << "front of vector:" << items.front() << std::endl;

  if (std::holds_alternative<Object>(obj.var)) {
    std::cout << "Value of obj0:" << std::get<Object>(obj.var) << std::endl;

    REQUIRE(std::get<Object>(obj.var).objId == 200);
  }
}
