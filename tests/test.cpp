#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>
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
  VarObject obj_a{a};
  REQUIRE(true == std::holds_alternative<Object>(obj_a.var));
  REQUIRE(200 == std::get<Object>(obj_a.var).objId);
  std::ostringstream str_stream{};

  str_stream << std::get<Object>(obj_a.var);

  REQUIRE(str_stream.str() == "200");

  VarObject obj_b{250};
  REQUIRE(true == std::holds_alternative<int>(obj_b.var));
  REQUIRE(250 == std::get<int>(obj_b.var));
  // Reset the stream
  str_stream.str("");
  str_stream.clear();
  str_stream << std::get<int>(obj_b.var);

  REQUIRE(str_stream.str() == "250");
}

TEST_CASE("Tests for Chapter3", "[Chapter3]") {
  Vector_CPP20<double> items{4, 8, 16, 4, 8, 16, 4, 8, 16};

  REQUIRE(4 == items.front());
  REQUIRE(16 == items.back());
  REQUIRE(9 == items.getSize());
}
