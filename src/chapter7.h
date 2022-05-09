#ifndef CHAPTER7_H
#define CHAPTER7_H

// TODO:Add requirements with concepts
template <typename T>
class GreaterThanNum {
  const T val;

 public:
  GreaterThanNum(const T& v) : val{v} {};
  bool operator()(const T& x) const { return x > val; };
};

#endif  // CHAPTER7_H
