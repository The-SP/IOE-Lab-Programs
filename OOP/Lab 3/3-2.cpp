// Lab 3
// Question 2
// Assume that you want to check whether the number is prime or not. Write a program that asks for numbers repeatedly. When it finishes checking a number the program asks if the user wants to do another calculation. The response can be 'y' or 'n'. Don't forget to use the object oriented concept.

#include <iostream>
using namespace std;

class CheckPrime {
    int n;
public:
    CheckPrime(int no) {
        n = no;
    }

    bool isPrime() {
        if (n<2)
            return false;
        for (int i=2; i<=n/2; i++) {
            if (n%i == 0)
                return false;
        }
        return true;
    }
};

int main() {
    int n;
    char choice;
    do {
        cout << "\nEnter a number? ";
        cin >> n;
        CheckPrime num(n);
        if (num.isPrime())
            cout << n << " is prime";
        else 
            cout << n << " is not a prime";
        cout << "\nEnter y to continue? ";
        cin >> choice;
    } while(choice == 'y');
}