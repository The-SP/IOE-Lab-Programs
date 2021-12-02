// Lab 8
// Question 3
// Write a program to overload stream operators to read a complex number and display the complex number in a+ib format.

#include <iostream>
using namespace std;

class Complex {
    int real, imag;
    friend istream& operator >> (istream& input, Complex& c) {
        cout << "Enter real and imaginary part: ";
        cin >> c.real >> c.imag;
        return input;
    }
    friend ostream& operator << (ostream& output, Complex& c) {
        cout << "Complex Number = " << c.real << " +i " << c.imag;
        return output;
    }
};

int main() {
    Complex c;
    cin >> c;
    cout << c;
}