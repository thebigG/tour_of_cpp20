#ifndef CHAPTER6_H
#define CHAPTER6_H

template <typename T>
class GreaterThan {
  const T val;

 public:
  GreaterThan(const T& v) : val{v} {};
  bool operator()(const T& x) const { return x > val; };
};

#endif  // CHAPTER6_H
