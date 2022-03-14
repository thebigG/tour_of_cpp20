export module Chapter3;
import<cstdint>;
import<exception>;
import<initializer_list>;
import<iostream>;

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
    validateRange(capacity);
    return elements[capacity - 1];
  }
  T front() {
    if (size == 0) {
      validateRange(size);
      return elements[size];
    } else {
      validateRange(size - 1);
      return elements[size - 1];
    }
  }
  //  ~Vector_CPP20() { delete[] elements; }

  void validateRange(int i) {
    if (i >= capacity || i < 0) {
      throw OutOfRangeException{};
    }
  }

  T& operator[](int i) {
    validateRange(i);

    return elements[i];
  }

 private:
  T* elements;
  const int MIN_CAPACITY = 16;
  int32_t size;
  int32_t capacity;
};
