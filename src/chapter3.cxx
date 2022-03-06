module;
#include <exception>
#include <iostream>
export module Chapter3;

export void func();
// export class OutOfRangeException;
export class OutOfRangeException : public std::exception {
 public:
  virtual ~OutOfRangeException(){};
  const char* what() const throw();
};

export template <typename T>
class Vector_CPP20 {
 public:
  // Implementations are defined here because I can't figure out a way
  // at the moment how to separate the interface from implementation in GCC 11.2
  // when working with templates and modules.
  Vector_CPP20() {
    elements = new T[MIN_SIZE];
    size = MIN_SIZE;
  }
  ~Vector_CPP20() { delete[] elements; }

  T& operator[](int i) {
    if (i >= size || i < 0) {
      throw OutOfRangeException{};
    }
    return elements[i];
  }

 private:
  T* elements;
  const int MIN_SIZE = 16;
  int size;
};
