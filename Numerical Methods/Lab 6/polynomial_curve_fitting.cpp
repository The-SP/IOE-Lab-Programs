// Least square method of curve fitting: Polynomial Equation
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int n, d;
    cout << "Enter no of data and degree of polynomial? ";
    cin >> n >> d;
    if (n < d) {
        cout << "Insufficient no of data";
        exit(1);
    }

    // Data read
    float x[n], y[n];
    cout << "Enter values of x and y:\n";
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    // Augmented Matrix declaration
    float a[d + 1][d + 2];
    for (int i = 0; i <= d; i++) {
        for (int j = 0; j <= d; j++) {
            a[i][j] = 0;
            for (int k = 0; k < n; k++)
                a[i][j] += pow(x[k], i + j);
        }
    }

    // d+1 th col
    for (int i = 0; i <= d; i++)
        for (int k = 0; k < n; k++)
            a[i][d + 1] += (pow(x[k], i) * y[k]);

    // Display augmented matrix
    cout << "\nAugmented matrix:\n";
    for (int i = 0; i <= d; i++) {
        for (int j = 0; j <= d + 1; j++)
            cout << setprecision(4) << a[i][j] << "\t\t";
        cout << endl;
    }
    cout << endl;

    // Gauss Jordan Method
    // Eliminating non-diagonal elements to create a diagonal matrix
    float ratio;
    for (int j = 0; j < d + 1; j++) {
        if (abs(a[j][j]) < 0.0001) {
            cout << "Error: Pivot element is zero";
            return 0;
        }
        for (int i = 0; i < d + 1; i++) {
            if (i != j) {
                ratio = a[i][j] / a[j][j];
                for (int k = j; k <= d + 1; k++)
                    a[i][k] -= ratio * a[j][k];
            }
        }
    }

    // Solutions
    cout << "The soulution is:\n";
    float ans;
    for (int i = 0; i < d + 1; i++) {
        ans = a[i][d + 1] / a[i][i];
        if (ans < 0.000001) ans = 0;
        cout << (char)('a' + i) << " = " << ans << endl;
    }
}