// Lab 2
// Question 6
/*
Write a program that displays the current monthly salary of chief executive officer, information officer, and system analyst, programmer that has been increased by 9, 10, 12, and 12 percentages respectively in year 2010. Let us assume that the salaries in year 2009 are
Chief executive officer Rs. 35000/m
Information officer Rs. 25000/m
System analyst Rs. 24000/m
Programmer Rs. 18000/m
Make function that takes two arguments; one salary and other increment. Use proper default argument.
*/

#include <iostream>
using namespace std;

struct Employee
{
  char position[30];
  int salary;
  int rate;
};

float newSalary(int salary, int percent) {
    return salary*(1+percent/100.f);
}

int main() {
    struct Employee e[] = {
        {"Chief Executive Officer", 35000, 9},
        {"Information Officer", 25000, 10},
        {"System Analyst", 24000, 12},
        {"Programmer", 18000, 12}
    };  

    cout << "Monthly salary for year 2009: \n";
    for (int i=0; i<sizeof(e)/sizeof(e[0]); i++)
        cout << e[i].position << " = Rs. " << e[i].salary <<endl;

    cout << "\nMonthly salary for year 2010: \n";
    for (int i=0; i<sizeof(e)/sizeof(e[0]); i++)
      cout << e[i].position << " = Rs. " << newSalary(e[i].salary,e[i].rate) <<endl;
}