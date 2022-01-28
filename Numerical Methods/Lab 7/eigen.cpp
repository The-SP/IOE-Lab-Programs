// Dominant eigen value and its corresponding eigenvector of the matrix using power method
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int n;
    float error;
    float a[10][10], x[10], y[10];
    cout << "Enter order of matrix and tolerable error? ";
    cin >> n >> error;
    // Matrix A
    cout << "Enter elements of matrix A? ";
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
    // Column vector X
    cout << "Enter elements of guess column vector X? ";
    for (int i=0; i<n; i++)
        cin >> x[i];

    // float a[][3] = {{-2, 3, 2}, {4, -2, 1}, {-1, 2, -9}};
    // float x[] = {1, 0, 0};
    // float y[3];
    // n = 3;
    // error = 0.0001;
    float max = 0;
    int flag, count = 1;

    do {
        max = 0; // reset max absolute eigen value

        // Matrix multiplication Y = AX
        for (int i = 0; i < n; i++) {
            y[i] = 0;
            for (int k = 0; k < n; k++) {
                y[i] += a[i][k] * x[k];
            }
            // Find largest eigen value
            if (abs(max) < abs(y[i])) max = y[i];
        }

        flag = 1; // initialize flag to 1 and later check if it is changed to 0

        // Display Y and assign new X = Y/max
        cout << "\n i=" << count++ << "\t max = " << max << "\tY = ";
        for (int i = 0; i < n; i++) {
            y[i] /= max;
            cout << setprecision(4) << y[i] << ' ';
            flag &= (abs(y[i] - x[i]) < error);
            x[i] = y[i]; // change col eigen vector X
        }
    } while (!flag && count < 100);

    // Ans
    cout << "\n\nDominant Eigen vlaue = " << max;
    cout << "\nCorresponding Eigen vector = ";
    for (int i = 0; i < n; i++)
        cout << x[i] << '\t';
}