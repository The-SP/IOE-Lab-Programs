// Lab 2
// Question 4
// Write a function that passes two temperatures by reference and sets the larger of the two numbers to a value entered by user by using return by reference.

#include <iostream>
using namespace std;


int& tempratures(int& a, int& b) {
    if (a > b)
        return a;
    else 
        return b;
}

int main() {
    int t1, t2;
    cout << "Enter temp1 and temp2? ";
    cin >> t1 >> t2;
    tempratures(t1,t2) = 100;
    cout << "Value of temp1 and temp2 after calling the fucntion"<< endl;
    cout << "temp1 = " << t1 << "\ntemp2 = " << t2;    
}