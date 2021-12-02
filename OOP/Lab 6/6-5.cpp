// Lab 6
// Question 5
// Write base class that ask the user to enter a complex number and make a derived class that adds the complex number of its own with the base. Finally make third class that is friend of derived and calculate the difference of base complex number and its own complex number.

#include <iostream>
using namespace std;

class Complex
{
public:
    float real, imag;
    Complex()
    {
        cout << "Enter real and imaginary part? ";
        cin >> real >> imag;
    }

    Complex(float r, float i)
    {
        real = r;
        imag = i;
    }

    void display()
    {
        cout << real << "+i" << imag << endl;
    }
};

class FriendCalculator;

class Calculator : public Complex
{
public:
    Complex operator+(Complex &c)
    {
        return Complex(real + c.real, imag + c.imag);
    }
    friend class FriendCalculator;
};

class FriendCalculator
{
public:
    Complex difference(Complex &a, Calculator &b)
    {
        return Complex(a.real - b.real, a.imag - b.imag);
    }
};

int main()
{
    Complex a;
    Calculator c;
    a.display();
    c.display();
    cout << "Sum = ";
    (c + a).display();
    cout << "Difference = ";
    FriendCalculator fCalc;
    fCalc.difference(a, c).display();
}