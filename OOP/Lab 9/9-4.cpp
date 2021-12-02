// Lab 9
// Question 4
// Write any program that demonstrates the use of multiple catch handling,
// re-throwing an exception, and catching all exception.

#include <iostream>
using namespace std;

void divide(double x, double y) {
  cout << "\nInside function\n";
  try {
    if (y == 0.0)
      throw y; // throwing double
    else if (y < 0)
      throw -1;
    else {
      cout << "x/y = " << x / y << endl;
      cout << "Success... Exception is not raised" << endl;
    }
  } catch (double) {
    cout << "Caught division by zero exception inside function\n";
    throw; // rethrow double
  } catch (int) {
    cout << "Caught division by negative exception inside function\n";
  }
  cout << "End of function\n";
}

int main() {
  cout << "Inside main\n";
  try {
    divide(10.5, 2.0);
    divide(10.5, 0.0);
  } catch (double) {
    cout << "Caught division by zero exception inside main()\n";
  }
  cout << "End of main\n";
}