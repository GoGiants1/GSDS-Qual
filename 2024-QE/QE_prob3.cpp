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