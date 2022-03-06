module;

export module Chapter4;

export {
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
}
