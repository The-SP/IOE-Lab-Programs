// Linear curve fitting 
// Fitting of line y = a + bx by the method of Least Squares

#include <iostream>
using namespace std;

int main() {
    int n;
    float x[20], y[20], ex, ey, exy, ex2, d, d1, d2, a, b;
    cout << "Enter no of datas? ";
    cin >> n;
    for (int i=0; i<n; i++) {
        cout << "(x, y) = ";
        cin >> x[i] >> y[i];
        ex += x[i];
        ey += y[i];
        exy += x[i]*y[i];
        ex2 += x[i]*x[i];
    }
    // ey = n*a + b*ex
    // exy = a*ex + b*ex2
    // Solving eqn by Cramer's rule
    d = n*ex2-ex*ex;
    d1 = ey*ex2-ex*exy;
    d2 = n*exy-ex*ey;
    a = d1/d;
    b = d2/d;
    char sign = b > 0 ? '+' : '-';
    cout << "Equation is  y = " << a << sign << abs(b) << "x" << endl;
}