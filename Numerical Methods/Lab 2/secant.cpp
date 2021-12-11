// Secant Method

#include <cmath>
#include <iostream>
using namespace std;

float f(float x) {
    return x * log10(x) - 1.2;      // (2,3) root=2.74
    // return pow(x, 4)-32;         // (2, 3) root=2.3784
}

int main() {
    float a, b, c, err;
    int i = 0;
    cout << "Enter initial guesses (a, b)? ";
    cin >> a >> b;
    cout << "Enter tolerable error? ";
    cin >> err;

    if (f(a) * f(b) > 0) {
        cout << "Initial guesses are incorrect!";
        return 0;
    }

    do {
        if (f(a) == f(b)) {
            cout << "Mathematical Error";
            return 0;
        }
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        a = b;
        b = c;
        if (++i > 5000) {
            cout << "Not convergent!";
            return 0;
        }
        cout << "i=" << i << "\tc=" << c << "\tf(c)=" << f(c) << endl;
    } while (abs(f(c)) > err);
    cout << endl;
    cout << "Required Root = " << c << endl;
    cout << "No of iterations = " << i;
}