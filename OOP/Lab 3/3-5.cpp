// Lab 3
// Question 5
/*
Assume that an object represents an employee report that contains information like employee id, total bonus, total overtime in a particular year. Use an array of objects to represent n employees' reports. Write a program that displays the report. Use setpara() member function to set report attributes by passing the arguments and member function displayreport() to show the report according to parameter passed. Display the report in following format.
Employee with ... ... ... has received Rs ... ... ...as bonus
and
had worked ... ... ... hours as a over time in  year ... ... ...
*/

#include <iostream>
using namespace std;

class Employee {
    int id, bonus, overtime, year;
public:
    void setpara(int i, int b, int o, int y) {
        id = i;
        bonus = b;
        overtime = o;
        year = y;
    }

    void displayreport() {
        cout << "Employee with id " << id << " has received Rs." << bonus << " as bonus and had worked"
             << overtime << " hours as a over time in year " << year << ".\n";
    }
};

int main() {
    cout << "Enter number of employees? ";
    int n;
    cin >> n;
    int id, b, o, y;
    Employee e[n];
    for (int i=0; i<n; i++) {
        cout << "Enter employee " << i+1 << " id,  total bonus, total overtime and a particular year? ";
        cin >> id >> b >> o >> y;
        e[i].setpara(id, b, o, y);
    }
    cout << endl;
    for (int i = 0; i< n ; i++) {
        e[i].displayreport();
    }
}