// Lab 5
// Question 3
// Write a program to compare two objects of a class that contains an integer value as its data member. Make overloading functions to overload equality(==), less than(<), greater than(>), not equal (!=), greater than or equal to (>=) and less than or equal to(<=) operators using member operator functions.

#include <iostream>
using namespace std;

class Integer {
    int n;

public:
    Integer(int sn): n(sn) {}

    bool operator==(Integer& a) {
        if (n == a.n)
            return true;
        else 
            return false;
    }  
    bool operator>(Integer& a) {
        if (n > a.n)
            return true;
        else 
            return false;
    }  
    bool operator<(Integer& a) {
        if (n < a.n)
            return true;
        else 
            return false;
    }  
    bool operator>=(Integer& a) {
        if (n >= a.n)
            return true;
        else 
            return false;
    }  
    bool operator<=(Integer& a) {
        if (n <= a.n)
            return true;
        else 
            return false;
    }  
};

int main()
{
    int n1, n2;
    cout << "Enter integer for object a and b? ";
    cin >> n1 >> n2;
    Integer a(n1), b(n2);
    if (a == b)
        cout << "Object a and b are equal"<< endl;
    if (a < b)
        cout << "Object a is less than b"<< endl;
    if (a > b)
        cout << "Object a is greater than b"<< endl;
    if (a <= b)
        cout << "Object a is less than or equal to b"<< endl;
    if (a >= b)
        cout << "Object a is greater than or equal to b"<< endl;
}