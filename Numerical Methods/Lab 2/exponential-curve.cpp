// Exponential curve fitting y = a*e^bx
// Data (0, 1.05), (1, 2.1), (2, 3.85), (3, 8.30)

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    float x[20], y[20], ex, eY, exY, ex2, d, d1, d2, A, a, b;
    cout << "Enter no of datas? ";
    cin >> n;
    for (int i=0; i<n; i++) {
        cout << "(x, y) = ";
        cin >> x[i] >> y[i];
        ex += x[i];
        eY += log(y[i]);
        exY += x[i]*log(y[i]);
        ex2 += x[i]*x[i];
    }
    /*
    y = a*e^bx
    ln(y) = ln(a) + bx
    Y = A + bx   where, A = ln(a)
    Normal eqns are
        eY = n*A + b*ex
        exY = A*ex + b*ex2
    Solving eqn by Cramer's rule
    */
    d = n*ex2-ex*ex;
    d1 = eY*ex2-ex*exY;
    d2 = n*exY-ex*eY;
    A = d1/d;
    a = exp(A);
    b = d2/d;
    cout << "Equation is  y = " << a << "e^" << b << "x" << endl;
}