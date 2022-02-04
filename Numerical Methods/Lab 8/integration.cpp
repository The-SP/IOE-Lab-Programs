// Newton-Cotes Quadrature Formula
// Discrete data for y=f(x) is given
#include <cmath>
#include <iostream>
using namespace std;

void trapezoidal(float a, float b, float h, int n, float y[]) {
    float integration = y[0] + y[n];
    for (int i = 1; i < n; i++)
        integration += 2 * y[i];
    integration *= (h / 2);
    cout << "Trapezoidal rule = " << integration << endl;
}

void simpson13rd(float a, float b, float h, int n, float y[]) {
    if (n % 2 != 0) {
        cout << "Simpson's 1/3 rule can't be evaluated with n = " << n << endl;
        return;
    }
    float integration = y[0] + y[n];
    int m;
    for (int i = 1; i < n; i++) {
        m = (i % 2 == 0) ? 2 : 4;
        integration += m * y[i];
    }
    integration *= (h / 3);
    cout << "Simpson's 1/3 rule = " << integration << endl;
}

void simpson38th(float a, float b, float h, int n, float y[]) {
    if (n % 3 != 0) {
        cout << "Simpson's 3/8 rule can't be evaluated with n = " << n << endl;
        return;
    }
    float integration = y[0] + y[n];
    int m;
    for (int i = 1; i < n; i++) {
        m = (i % 3 == 0) ? 2 : 3;
        integration += m * y[i];
    }
    integration *= (3 * h / 8);
    cout << "Simpson's 3/8 rule = " << integration << endl;
}

int main() {
    int n;
    cout << "Enter no of sub-intervals: ";
    cin >> n;
    float a, b, h, y[20];
    cout << "Enter limits of integration (a, b): ";
    cin >> a >> b;
    for (int i = 0; i <= n; i++) {
        cout << "y" << i << ": ";
        cin >> y[i];
    }
    h = (b - a) / n;
    trapezoidal(a, b, h, n, y);
    simpson13rd(a, b, h, n, y);
    simpson38th(a, b, h, n, y);
}