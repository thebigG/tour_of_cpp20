module Chapter4;

Complex::Complex(double newReal, double newImaginary)
    : real{newReal}, imaginary{newImaginary} {}

Complex::Complex(double newReal) : real{newReal}, imaginary{0} {}

Complex::Complex() : real{0}, imaginary{0} {}

double Complex::getReal() const { return real; }

double Complex::getImaginary() const { return imaginary; }
