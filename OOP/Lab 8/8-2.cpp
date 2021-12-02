// Lab 8
// Question 2
// Write a program to create a user-defined manipulator that will format the
// output by setting the width, precision, and fill character at the same time
// by passing arguments.

#include <iomanip>
#include <iostream>
using namespace std;

class Manipulator {
  int width, precision;
  char fill;

public:
  Manipulator(int w, int p, char f) : width(w), precision(p), fill(f){};
  friend ostream &operator<<(ostream &str, Manipulator obj);
};
ostream &operator<<(ostream &output, Manipulator obj) {
  output << setw(obj.width) << setfill(obj.fill) << setprecision(obj.precision);
  return output;
}
// Manipulator setwpf(int w, int p, char f) { return Manipulator(w, p, f); }

int main() {
  cout << "Using user-defined manipulator:" << endl;
  cout << Manipulator(7, 4, '$') << 5.632509;
}