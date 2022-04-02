#include <stdint.h>

struct Point {};
class Complex {
 private:
  double real;
  double imaginary;

 public:
  Complex(double newReal, double newImaginary);
  Complex(double newReal);
  Complex();
  double getReal() const;
  double getImaginary() const;
};

class Shape {
 public:
  virtual Point center()
      const = 0;  // Pure virtual("Abstract" in other high-level languages)
  virtual void move(Point to) = 0;
  virtual void draw() const = 0;
  virtual void rotate(int32_t angle) = 0;
};
class Circle : Shape {};
