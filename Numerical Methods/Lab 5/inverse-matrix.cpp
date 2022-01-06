// Inverse of Matrix Using Gauss Jordan Method

#include <iostream>
using namespace std;

int main() {
    float a[20][20], ratio;
    int n;
    cout << "Enter order of matrix? ";
    cin >> n;

    // Data entry
    cout << "Enter the elements of matrix \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            // To initialize elements of Identity matrix in [A | I]
            if (i == j)
                a[i][j + n] = 1;
            else
                a[i][j + n] = 0;
        }

    // Display Augmented Matrix [A | I]
    cout << "\nDisplaying [A | I]\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if (j == n) cout << " | ";
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    // Gauss Jordan Method
    // Eliminating non-diagonal elements to create a diagonal matrix
    for (int j = 0; j < n; j++) {
        if (abs(a[j][j]) < 0.00001) {
            cout << "Error: Pivot element is zero";
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (i != j) {
                ratio = a[i][j] / a[j][j];
                for (int k = j; k < 2 * n; k++)
                    a[i][k] -= ratio * a[j][k];
            }
        }
    }

    // Inverse Matrix Calculation
    cout << "\nThe inverse matrix is \n";
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            // dividing by pivot element
            a[i][j] /= a[i][i];
        }
    }

    // Display Inverse matrix
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}