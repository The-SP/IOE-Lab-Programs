// Lab 8
// Question 1
// Write a program to demonstrate the use of different ios flags and functions
// to format the output. Create a program to generate the bill invoice of a
// department store by using different formatting.

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  ofstream bill("bill.txt", ios::out);
  int id = 1, qt;
  float price, subtotal, total = 0;
  char part[20];
  char choice;
  bill << setw(40) << "Amazon E-Commerce Company" << endl;
  cout << setw(40) << "Amazon E-Commerce Company" << endl;
  bill << setw(6) << "S.No. " << setw(20) << left << "Particulars " << setw(10)
       << "Quantity " << setw(6) << "Price " << setw(10) << "Sub-total "
       << endl;
  do {
    cout << "Particulars = ";
    cin >> part;
    cout << "Quantity = ";
    cin >> qt;
    cout << "Price = ";
    cin >> price;
    cout << "Sub-Total = ";
    subtotal = qt * price;
    cout << subtotal << endl;
    total += subtotal;
    bill << setw(6) << id++ << setw(20) << left << part << setw(10) << qt
         << setw(6) << price << setw(10) << subtotal << endl;
    cout << "Do you want to continue (y/n)";
    cin >> choice;
  } while (choice == 'y');
  cout << "Total = " << total;
  bill << setw(40) << "Total"
       << "= " << total << endl;
  bill.close();
}