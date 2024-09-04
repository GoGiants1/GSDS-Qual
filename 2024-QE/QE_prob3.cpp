
/*
implement a class named Complex to represent complex numbers. A complex number is of the form a + bi where a and b are real numbers and i^2 = -1.
a is referred to as the real part of the complex number, and bi is the imaginary number.

Define a class named Complex with two private data members, real and imag of type double.
Implemen a constructor that takes two double arguments and initializes real and imag respectively, and the following member functions.
    double getReal(){}
    double getImag(){}
    void setReal(double _real){}
    void setImag(double _imag){}

implement an overloaded addition operator to return the sum of two Complex objects.
    a + bi addition c + di = (a+c) + (c+d)i

implement an overloaded negation operator (unary-) that will negate both the real and imaginary parts of a complex number
    negation (2+4i) = -2-4i

implement an overloaded << operator to print in a form of real + imag i. 
it rhe imaginary component is zero, output only the real component.
if the imaginary part is negative, replace + symbol with -.

you can only include followings.
    #include <iostream>
    #include <cstdio>
    #include <iomanip>
    #include <string>
    #include <cmath>

*/


#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Complex {
 public:
  Complex() : real(0.0), imag(0.0) {}
  Complex(double r, double i) : real(r), imag(i) {}

  double getReal() const { return real; }
  double getImag() const { return imag; }

  void setReal(double r) { real = r; }
  void setImag(double i) { imag = i; }

  Complex operator-() const { return Complex(-real, -imag); }

  Complex operator+(const Complex& B) const {
    return Complex(real + B.real, imag + B.imag);
  }

  friend ostream& operator<<(ostream& os, const Complex& A);

 private:
  double real, imag;
};

ostream& operator<<(ostream& os, const Complex& A) {
  os << A.real;
  if (A.imag > 0) {
    os << "+" << A.imag << "i";
  } else if (A.imag < 0) {
    os << A.imag << "i";
  }
  return os;
}

// int main() {
//   cout << fixed;
//   Complex c1(3.3, 2.6);

//   Complex c2, c3;
//   c2.setReal(7.89);
//   c2.setImag(-9.21);

//   c3 = c1 + c2;

//   cout << "The Sum is " << c3 << endl;
//   cout << "The Real part is " << c3.getReal() << endl;
//   cout << "The Imag part is " << c3.getImag() << endl;

//   cout << "Negation of c3: " << -c3 << endl;

//   return 0;
// }