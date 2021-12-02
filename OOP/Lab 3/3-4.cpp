// Lab 3
// Question 4
// Write a program with classes to represent circle, rectangle, and triangle. Each class should have data members to represent the actual objects and member functions to read and display objects, find perimeter and area of the objects, and other useful functions. Use the classes to create objects in your program.

#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14

class Circle
{
    float radius;

public:
    Circle()
    {
        cout << "Enter radius of a circle: ";
        cin >> radius;
    }

    float perimeter() { return 2 * PI * radius; }
    float area() { return PI * radius * radius; }

    void displayInfo()
    {
        cout << "Circle:\n";
        cout << "Radius = " << radius;
        cout << "\nPerimeter = " << perimeter();
        cout << "\nArea = " << area();
    }
};

class Rectangle
{
    float l, b;

public:
    Rectangle()
    {
        cout << "Enter length and breadth of rectangle? ";
        cin >> l >> b;
    }

    float perimeter() { return 2 * (l + b); }
    float area() { return l * b; }

    void displayInfo()
    {
        cout << "Rectangle:\n";
        cout << "Length = " << l;
        cout << "\nBreadth = " << b;
        cout << "\nPerimeter = " << perimeter();
        cout << "\nArea = " << area();
    }
};

class Triangle
{
    float a, b, c;

public:
    Triangle()
    {
        cout << "Enter 3 sides of a triangle? ";
        cin >> a >> b >> c;
    }

    float perimeter() { return a + b + c; }
    float area()
    {
        float s = perimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void displayInfo()
    {
        cout << "Triangle:\n";
        cout << "3 sides = " << a << " " << b << " " << c;
        cout << "\nPerimeter = " << perimeter();
        cout << "\nArea = " << area();
    }
};

int main()
{
    Circle circle;
    Rectangle rect;
    Triangle triangle;
    cout << endl;
    circle.displayInfo();
    cout << "\n\n";
    rect.displayInfo();
    cout << "\n\n";
    triangle.displayInfo();
}