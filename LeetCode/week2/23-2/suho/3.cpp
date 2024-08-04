#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape{
public:
    string get_name(){return "Shape";};
protected:
    virtual double calc_area() {return 0;};
};

// string Shape::get_name() {
//     return "Shape";
// }

class Rectangle : public Shape {
protected:
    double width;
    double height;
public:
    Rectangle(): width(1), height(1) {};
    Rectangle(double w, double h): width(w), height(h) {};
    virtual double calc_area() { return width * height ;};
    string get_name(){return "Rectangle";};
};

// Rectangle::Rectangle(double w, double h) {
//     width = w;
//     height = h;
// }

class Square : public Rectangle {
public:
    Square(double l) : Rectangle(l, l) {};
    string get_name(){return "Square";};
};

class Triangle : public Shape {
protected:
    double a, b, c;
public:
    Triangle(): a(1), b(1), c(1) {};
    Triangle(double a, double b, double c): a(a), b(b), c(c) {};
    virtual double calc_area();
    string get_name(){return "Triangle";};
};

double Triangle::calc_area(){
    double s = (a+b+c)/2;
    double area =  sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
} 

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b) : Triangle(a, b, sqrt(a*a + b*b)) {};
    virtual double calc_area() { return a*b/2; };
    string get_name(){return "RightTriangle";};
};

int main(){
    Rectangle R = Rectangle(1., 2.);
    Square S = Square(3.);
    Triangle T = Triangle(1,3,3);
    RightTriangle RT = RightTriangle(3,4);

    cout << "Rectangle" << endl;
    cout << "Name: " << R.get_name() << endl;
    cout << "Area = " << R.calc_area() << endl;
    cout << endl;
    
    cout << "Square" << endl;
    cout << "Name: " << S.get_name() << endl;
    cout << "Area = " << S.calc_area() << endl;
    cout << endl;

    cout << "Triangle" << endl;
    cout << "Name: " << T.get_name() << endl;
    cout << "Area = " << T.calc_area() << endl;
    cout << endl;

    cout << "RightTriangle" << endl;
    cout << "Name: " << RT.get_name() << endl;
    cout << "Area = " << RT.calc_area() << endl;
    cout << endl;

    return 0;
}
