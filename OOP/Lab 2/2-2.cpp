// Lab 2
// Question 2
// Write a program using the function overloading that converts feet to inches. Use function with no argument, one argument and two arguments. Decide yourself the types of arguments. Use pass by reference in any one of the function above.


#include <iostream>
using namespace std;

void convert()
{
    int feet, inch;
    cout << "Feet? ";
    cin >> feet;
    inch = feet * 12;
    cout << feet << " feet = " << inch << " inches\n";
}

float convert(float feet) {
    return feet*12;
}

void convert(int feet, int& inch) {
    inch = feet * 12;
}

int main()
{
    convert(); // no argument
    cout << "5.5 feet = " << convert(5.5) << " inches\n"; // 1 argument
    int feet = 6, inch;
    convert(feet, inch); // 2 argument and using reference
    cout << feet << " feet = " << inch << " inches";
}