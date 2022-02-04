// Newton-Cotes Quadrature Formula
// Function y=f(x) is given
#include <cmath>
#include <iostream>
using namespace std;

float f(int x) {
    return 1 / (1 + pow(x, 2));
}

void trapezoidal(float a, float b, int n) {
    float h = (b-a)/n;
    float integration = f(a) + f(b);
    for (int i = 1; i < n; i++)
        integration += 2*f(a+i*h);
    integration *= (h / 2);
    cout << "Trapezoidal rule = " << integration << endl;
}

void simpson13rd(float a, float b, int n) {
    if (n%2 != 0)
        n = n+1;
    float h = (b-a)/n;
    float integration = f(a) + f(b);
    int m;
    for (int i = 1; i < n; i++) {
        m = (i%2 == 0) ? 2 : 4;
        integration += m*f(a+i*h);            
    }
    integration *= (h/3);
    cout << "Simpson's 1/3 rule = " << integration << endl;
}

void simpson38th(float a, float b, int n) {
    if (n % 3 != 0)
        n += (3-n%3);
    float h = (b-a)/n;
    float integration = f(a) + f(b);
    int m;
    for (int i = 1; i < n; i++) {
        m = (i%3 == 0) ? 2 : 3;
        integration += m*f(a+i*h);            
    }
    integration *= (3*h/8);
    cout << "Simpson's 3/8 rule = " << integration << endl;
}

int main() {
    int n;
    cout << "Enter no of sub-intervals: ";
    cin >> n;
    float a, b;
    cout << "Enter limits of integration (a, b): ";
    cin >> a >> b;
    trapezoidal(a, b, n);
    simpson13rd(a, b, n);
    simpson38th(a, b, n);
}