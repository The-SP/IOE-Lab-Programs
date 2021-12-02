// Lab 2
// Question 5
// Assume that employee will have to pay 10 percent income tax to the government. Ask user to enter the employee salary. Use inline function to display the net payment to the employee by the company.

#include <iostream>
using namespace std;

inline float netPayment (int s, int rate) {return (s-s*rate/100.f);}

int main() {
    int s;
    cout << "Enter employee salary? ";
    cin >> s;
    cout << "Net payment to the employee by the company = " << netPayment(s, 10);
}