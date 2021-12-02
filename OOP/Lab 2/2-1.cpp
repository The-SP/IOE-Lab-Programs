// Lab 2
// Question 1
// Write a program to set a structure to hold a date (mm,dd and yy), assign values to the members of the structure and print out the values in the format 11/28/2004 by function. Pass the structure to the function


#include <iostream>
using namespace std;

struct Date {
    int day, month, year;
};

void getDate(Date& d) {
    bool success = false;
    cout << "Enter date, month and year? ";
    cin >> d.day >> d.month >> d.year;
    if (d.day < 1 || d.day > 32) {
	  cout << "date must be between 1 to 32" << endl;
    } else if (d.month < 1 || d.month > 12) {
        cout << "Month must be between 1 to 12" << endl;
    } else {
        success = true;
    }
    if (!success)
        getDate(d);
}

void displayDate(Date d) {
    cout << "Date: " << d.month << "/" << d.day << "/" << d.year;
}

int main() {
    Date d;
    getDate(d);
    displayDate(d);
}