// Lab 9
// Question 1
// Create a function called sum ( ) that returns the sum of the elements of an array. Make this function into a template so it will work with any numerical type. Write a main ( ) program that applies this function to data of various type.

#include <iostream>
using namespace std;

template <typename T>
T sum(T arr[], int n) {
    T s=0;
    for (int i=0; i<n; i++) s+=arr[i];
    return s;
}

int main() {
    int num[] = {4, 5, 10, 7};
    float fnum[] = {2.3, 5.7, 6.3, 7.1};
    cout << "Sum of integers = " << sum(num, 4) << endl;
    cout << "Sum of floats = " << sum(fnum, 4);    
}