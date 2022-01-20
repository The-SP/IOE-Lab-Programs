#include <iostream>
using namespace std;

long int fibonacci(long int n) {
    if (n == 1 || n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << fibonacci(10);
}