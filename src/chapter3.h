#include <cstdint>
#include <exception>
#include <initializer_list>
#include <iostream>

// export class OutOfRangeException;
class OutOfRangeException : public std::exception {
 public:
  virtual ~OutOfRangeException(){};
  const char* what() const throw();
};

template <typename T>
class Vector_CPP20 {
 public:
  Vector_CPP20() {
    elements = new T[MIN_CAPACITY];
    size = 0;
    capacity = MIN_CAPACITY;
  }
  Vector_CPP20(std::initializer_list<T> list) {
    elements = new T[MIN_CAPACITY];
    size = 0;
    capacity = MIN_CAPACITY;
    for (auto& item : list) {
      pushBack(item);
    }
  }

  void pushBack(T& newElement) {
    validateRange(size);
    elements[size] = newElement;
    ++size;
  }

  void pushBack(T newElement) {
    validateRange(size);
    elements[size] = newElement;
    ++size;
  }

  T back() {
    if (size == 0) {
      validateRange(size);
      return elements[size];
    } else {
      validateRange(size - 1);
      return elements[size - 1];
    }
  }
  T front() {
    validateRange(capacity - 1);
    return elements[0];
  }
  ~Vector_CPP20() { delete[] elements; }

  void validateRange(int i) {
    if (i >= capacity || i < 0) {
      throw OutOfRangeException{};
    }
  }

  T& operator[](int i) {
    validateRange(i);

    return elements[i];
  }

  int32_t getSize() { return size; }

 private:
  T* elements;
  const int MIN_CAPACITY = 16;
  int32_t size;
  int32_t capacity;
};
