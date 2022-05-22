#ifndef CHAPTER7_H
#define CHAPTER7_H

#include <concepts>
#include <iostream>

template <typename T>
concept Comparable = requires(T a, T b) {
  a > b&& a < b&& a == b&& a != b&& a <= b&& a >= b;
};

template <typename T>
concept Addable = requires(T a, T b) {
  a + b;
};

template <typename T>
concept Substractable = requires(T a, T b) {
  a - b;
};

template <typename T>
concept Dividable = requires(T a, T b) {
  a / b;
};

template <typename T>
concept Multipliable = requires(T a, T b) {
  a* b;
};

template <typename T>
concept Number = requires(T a, T b) {
  Comparable<T>&& Addable<T>&& Substractable<T>&& Dividable<T>&&
      Multipliable<T>;
};

// Same as GreaterThan in Chapter6 except that here we enforce the concept of
// "Number" at compile time
template <typename T>
requires Number<T>
class GreaterThanNum {
  const T val;

 public:
  GreaterThanNum(const T& v) : val{v} {};
  bool operator()(const T& x) const { return x > val; };
};

template <typename... T>
void write_to_stream(std::ostringstream& stream, T... items) {
  // Fold our args
  (stream << ... << items);
}

#endif  // CHAPTER7_H
