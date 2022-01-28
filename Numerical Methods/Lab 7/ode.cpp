// Ordinary differential equations (initial value problem) using RK-4 method
#include <iostream>
#include <cmath>
using namespace std;

float f(float x, float y, float z) {
    return 0.5*(-x-pow(y, 3)/3+y);
    // return z;
}
float g(float x, float y, float z) {
    return 2 * y - 3 * z;
    // return -x*z-y;
}

int main() {
    float x, y, z, xn, h;
    float k1, k2, k3, k4, l1, l2, l3, l4, k, l;
    int n;
    cout << "Enter initial values of x, y and z? ";
    cin >> x >> y >> z;
    cout << "Enter xn and n? ";
    cin >> xn >> n;
    h = (xn - x) / n;
    for (int i = 1; i <= n; i++) {
        k1 = h * f(x, y, z);
        l1 = h * g(x, y, z);
        k2 = h * f(x + h / 2, y + k1 / 2, z + l1 / 2);
        l2 = h * g(x + h / 2, y + k1 / 2, z + l1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2, z + l2 / 2);
        l3 = h * g(x + h / 2, y + k2 / 2, z + l2 / 2);
        k4 = h * f(x + h, y + k3, z + l3);
        l4 = h * g(x + h, y + k3, z + l3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        x += h;
        y += k;
        z += l;
        // cout << i << "\t" << x << "\t" << y << '\t' << z << endl;
    }
    cout << "\nFinal solution (x, y, z) :\n";
    cout << x << '\t' << y << '\t' << z;
}