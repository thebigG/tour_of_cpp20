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

TEST_CASE("Tests for Chapter2", "[Chapter2]") {
  Object a{200};
  VarObject obj{a};
  REQUIRE(true == std::holds_alternative<Object>(obj.var));
  REQUIRE(200 == std::get<Object>(obj.var).objId);
}

TEST_CASE("Tests for Chapter3", "[Chapter3]") {
  Vector_CPP20<double> items{4, 8, 16, 4, 8, 16, 4, 8, 16};

  REQUIRE(4 == items.front());
  REQUIRE(16 == items.back());
  REQUIRE(9 == items.getSize());
}
