// Lab 5
// Question 2
// Write a class to store x, y, and z coordinates of a point in three-dimensional space. Overload addition and subtraction operators for addition and subtraction of two coordinate objects. Implement the operator functions as non-member functions (friend operator functions).

#include <iostream>
using namespace std;

class Point
{
    float x, y, z;

public:
    Point() {}
    Point(float a, float b, float c) : x(a), y(b), z(c) {}

    friend Point operator+(Point &, Point &);
    friend Point operator-(Point &, Point &);

    void display()
    {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

Point operator+(Point &a, Point &b)
{
    return Point(a.x + b.x, a.y + b.y, a.z + b.z);
}

Point operator-(Point &a, Point &b)
{
    return Point(a.x - b.x, a.y - b.y, a.z - b.z);
}

int main()
{
    Point a(3, 5.6, 8.8), b(2.5, 2.3, 1.2);
    cout << "a = ";
    a.display();
    cout << "b = ";
    b.display();
    Point sum, diff;
    sum = a + b;
    diff = a - b;
    cout << "Sum = ";
    sum.display();
    cout << "Difference = ";
    diff.display();
}