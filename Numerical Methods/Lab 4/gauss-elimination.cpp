#include <iostream>
using namespace std;

int main() {
    int n;
    float a[20][20];
    float ratio;
    int i, j, k;
    cout << "Enter no of unknowns? ";
    cin >> n;

    // Data entry
    cout << "\nEnter the element of augmented matrix:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++) {
            cout << "A(" << i << "," << j << ") = ";
            cin >> a[i][j];
        }

    // Gauss Elimination method
    for (j = 0; j < n - 1; j++) {
        if (abs(a[j][j]) <= 0.0005) {
            cout << "Error: Pivot element is zero";
            return 0;
        }
        for (i = j + 1; i < n; i++) {
            ratio = a[i][j] / a[j][j];
            for (k = j; k <= n; k++)
                a[i][k] -= ratio * a[j][k];
        }
    }

    // Solutions by Backward Substitution
    cout << "\nThe solution is:\n";
    float x[n], sum;
    for (i = n - 1; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j < n; j++)
            sum += a[i][j] * x[j];
        x[i] = (a[i][n] - sum) / a[i][i];
        cout << char('z'-(n-1)+i) << " = " << x[i] << endl;
    }        
}

// Theory:
// Change to upper triangular form
// for j = 1 to (n-1)
//     for i = (j+1) to n
//         R_i = R_i - (a_ij/a_jj)*R_j

// Back substitution
// x4 = a45/a44
// x3 = (a45-a34*x4)/a33
// x2 = (a25-a23*x3-a24*x4)/a22
// x1 = (a15-a12*x2-a13*x3-a14*x4)/a11
// In general,
//      xi = (a_i,n+1 - [j=i+1 to n => a_ij*x_j])/a_ii
// Loop,
//      while i = n-1 to 1 (countdown)

// Question
// x+2y+3z-u=10
// 2x+3y-3z-u=1
// 2x-y+2z+3u=7
// 3x+2y-4z+3u=2
// Ans = 1, 2, 2, 1