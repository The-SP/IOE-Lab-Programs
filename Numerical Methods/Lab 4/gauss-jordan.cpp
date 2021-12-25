#include <iostream>
using namespace std;

int main() {
    float a[20][20], ratio;
    int n;
    cout << "Enter no of unknowns? ";
    cin >> n;
    
    // Data entry
    cout << "Enter the elements of augmented matrix \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++) {
            cout << "A(" << i << "," << j << ") = ";
            cin >> a[i][j];
        }

    // Gauss Jordan Method
    // Eliminating non-diagonal elements to create a diagonal matrix
    for (int j = 0; j < n; j++) {
        if (abs(a[j][j]) <= 0.00005) {
            cout << "Error: Pivot element is zero";
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (i != j) {
                ratio = a[i][j] / a[j][j];
                for (int k = j; k <= n; k++)
                    a[i][k] -= ratio * a[j][k];
            }
        }
    }

    // Solutions
    char var = 'z' - (n - 1);
    cout << "\nThe solution is:\n";
    for (int i = 0; i < n; i++) {
        cout << char(var + i) << " = " << a[i][n] / a[i][i] << endl;
    }
}

// To eliminate a_ij
//      R_i = R_i - (a_ij/a_jj)*R_j
// where,
//      a_ij = element being eliminated
//      a_jj = pivot element

// Question
// x+y+z=9
// 2x-3y+4z=13
// 3x+4y+5z=40
// Ans: x=1, y=3, z=5