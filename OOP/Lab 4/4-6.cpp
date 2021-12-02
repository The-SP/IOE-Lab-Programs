// Lab 4
// Question 6
// Create a class with a data member to hold a "serial number" for each object created from the class. That is, the first object created will be numbered 1, the second 2, and so on by using the basic concept of static data members. Use static member function if it is useful in the program. Otherwise, make a separate program that demonstrates the use of static member function.

#include <iostream>
using namespace std;

class Number
{
    int serialNo;
    static int total;

public:
    Number()
    {
        increaseCount();
        serialNo = total;
    }

    void display()
    {
        cout << "Serial number = " << serialNo << "\tTotal = " << total << endl;
    }
    
    static void increaseCount()
    {
        total++;
    }
};
int Number::total = 0;

int main()
{
    Number n1, n2;
    n1.display();
    n2.display();
}