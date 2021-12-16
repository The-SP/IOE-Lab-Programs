#include <iostream>
using namespace std;

float f(float x, float y) {
    return x+y;
}

int main() {
    float x, y, xn, h, m1, m2, m;
    int n;
    cout << "Enter initial values? ";
    cin >> x >> y;
    cout << "Enter no of steps and final point? ";
    cin >> n >> xn;
    h = (xn-x)/n;
    for (int i=1; i<=n; i++) {
        m1 = f(x, y);
        m2 = f(x+h, y+m1*h);
        m = (m1+m2)/2;
        y += h*m;
        x += h;
        cout << i << "\t" << x << "\t" << y << endl;
    }
}