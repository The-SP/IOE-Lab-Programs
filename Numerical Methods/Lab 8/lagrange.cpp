#include <iostream>
using namespace std;

int main() {
    int n;
    float x[20], y[20], a;
    cout << "Enter no of data: ";
    cin >> n;
    cout << "Enter values of x and y: \n";
    for (int i=0; i<n; i++) {
        cout << "(x, y) = ";
        cin >> x[i] >> y[i];
    }
    cout << "Enter value of x to find the respective value of y: ";
    cin >> a;
    float product, sum = 0;
    for (int i=0; i<n; i++) {
        product = 1;
        for (int j=0; j<n; j++)
            if (i != j)
                product *= (a-x[j])/(x[i]-x[j]);
        sum += product*y[i];
    }
    cout << endl << "y at x=" << a << " is " << sum;
}