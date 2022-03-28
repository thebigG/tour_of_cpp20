#ifndef CHAPTER2_H
#define CHAPTER2_H
#include <variant>
class VarObject {
 public:
  //    VarObject(int newVarVal);
  //    VarObject(Object newVarVal);
  int num;
  std::variant<int, float> x = 12;
};

#endif  // CHAPTER2_H
