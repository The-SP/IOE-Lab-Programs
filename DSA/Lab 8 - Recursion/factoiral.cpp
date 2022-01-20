#include <iostream>
using namespace std;

long int factorial(long int n) {
    if (n == 1) return 1;
    return n * factorial(n-1);
}

int main() {
    int n;
    cout << "Enter a no? ";
    cin >> n;
    cout << "Factorial of " << n << " = " << factorial(n);
}