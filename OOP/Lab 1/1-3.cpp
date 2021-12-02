// Lab 1
// Question 3
// Store and retrieve the name of the students and obtained marks in c programming in 1st semester using structure.


#include <iostream>
using namespace std;

struct Student {
    char name[20];
    int marksInC;
};


int main()
{
    cout << "Enter number of students: ";
    int n;
    cin >> n;

    Student s[n];
    for (int i=0; i<n; i++) {
        cout << "Enter name of student " << i+1 << ": ";
        cin >> s[i].name;
        cout << "Enter marks obtained in C: ";
        cin >> s[i].marksInC;
    }

    cout << "\nRetrieving students information\n";
    for (int i=0; i<n; i++) {
        cout << "Name of student = " << s[i].name << endl;
        cout << "Marks obtained in C = " << s[i].marksInC << endl;
        cout << endl;
    }
}