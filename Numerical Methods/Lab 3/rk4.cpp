#include <iostream>
using namespace std;

float f(float x, float y) {
    return x+y;
}

int main() {
    float x, y, xn, h, m1, m2, m3, m4, m;
    int n;
    cout << "Enter initial values? ";
    cin >> x >> y;
    cout << "Enter no of steps and final point? ";
    cin >> n >> xn;
    h = (xn-x)/n;
    for (int i=1; i<=n; i++) {
        m1 = f(x, y);
        m2 = f(x+h/2, y+m1*h/2);
        m3 = f(x+h/2, y+m2*h/2);
        m4 = f(x+h, y+m3*h);
        m = (m1+2*m2+2*m3+m4)/6;
        y += h*m;
        x += h;
        cout << i << "\t" << x << "\t" << y << endl;
    }
}