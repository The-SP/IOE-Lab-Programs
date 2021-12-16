// Newton-Raphson Method

#include <cmath>
#include <iostream>
using namespace std;

#define dx 0.000001

float f(float x) {
    return x * log10(x) - 1.2; // x=2, root=2.74
    // return 3*x-cos(x)-1;     // x=0.6, root=0.607
    // return x * (1 - x); // x=0.5, Mathematical error since f1(x)=0
}

float f1(float x) {
    return (f(x + dx) - f(x)) / dx;
}

int main() {
    float x, err;
    int i = 0;
    cout << "Enter initial guess and tolerable error? ";
    cin >> x >> err;
    do {
        if (abs(f1(x)) < 0.0005f) {
            cout << "Mathematical error" << endl;
            return 0;
        }
        x -= f(x) / f1(x);
        if (++i > 5000) {
            cout << "Not convergent!";
            return 0;
        }
        cout << "i=" << i << "\t x=" << x << "\t f(x)=" << f(x) << endl;
    } while (abs(f(x)) > err);
    cout << "Root = " << x << endl;
    cout << "No of iterations = " << i;
}