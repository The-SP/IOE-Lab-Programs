// Lab 5
// Question 1
/*
Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.
A. Make a particular member function of one class as a friend function of another class for addition.
B. Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.
C. Also write a small program to demonstrate that all the member functions of one class are the friend functions of another class if the former class is made friend to the latter.
Make least possible classes to demonstrate all the above in a single program without conflict.
*/


#include <iostream>
using namespace std;

class Point;

class Calculator
{
public:
    // not defined here due to incomplete type error
    static Point add(Point&, Point&);
    static Point difference(Point&, Point&); 
};

class Point
{
    int x, y;

public:
    Point() {}
    Point(int a, int b) : x(a), y(b) {}

    void display()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

// 5.1(a) add() and difference() member functions of Calculator are friend function of class Point
    friend Point Calculator::add(Point&, Point&); 
    friend Point Calculator::difference(Point&, Point&);
// 5.1(c) Calc2 class is friend to class Point
    friend class Calc2;
};

class Calc2 {
public:
    static Point multiply(Point &a, Point &b) {
        return Point(a.x*b.x, a.y*b.y);
    };
    static Point divide(Point &a, Point &b) {
        return Point(a.x/b.x, a.x/b.y);
    }
};

Point Calculator::add(Point &a, Point &b)
{
    return Point(a.x+b.x, a.y+b.y);
}

Point Calculator::difference(Point &a, Point &b)
{
    return Point(a.x-b.x, a.y-b.y);
}

int main()
{
    Point a(5, 3), b(3, 6), sum, diff, mul, div;
    cout << "a = ";
    a.display();
    cout << "b = ";
    b.display();
    sum = Calculator::add(a, b);
    diff = Calculator::difference(a, b);
    mul = Calc2::multiply(a, b);
    div = Calc2::divide(a, b);
    cout << "Sum = ";
    sum.display();
    cout << "Difference = ";
    diff.display();
    cout << "Multiplication = ";
    mul.display();
    cout << "Division = ";
    div.display();
}