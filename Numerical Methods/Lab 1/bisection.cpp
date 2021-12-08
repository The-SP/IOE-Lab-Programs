#include <iostream>
#include <math.h>
using namespace std;

float func(float x){
    return x*sin(x)+cos(x);
    // return x*log(x)-4;
    // return 1/pow(x,3)+sin(x);
}

int main() {
    float a, b, err, c, fc;
    int count = 0;
    cout << "Enter initial guesses (a, b)? ";
    cin >> a >> b;
    cout << "Enter tolerable error? ";
    cin >> err;

    if (func(a)*func(b) > 0) { // a and b gives same sign
        cout << "Initial guesses are wrong!";
        return 0;
    }

    if (func(a) == 0)
        cout << "Root = " << a;
    else if (func(b) == 0)
        cout << "Root = " << b;
    else {
        do {
            c = (a+b)/2;
            fc = func(c);
            if (fc*func(a) > 0) // a and c gives same sign
                a = c;
            else    
                b = c;
            
            if (++count > 5000) {
                cout << "The function is discontinous.";
                return 0;
            }

            cout << "Iteration " << count << "\tc=" << c << "\tf(c)=" << fc << endl;
        }while(abs(fc) > err);
        cout << "Root = " << c;
    }
}