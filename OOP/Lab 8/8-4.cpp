// Lab 8
// Question 4
// Write a program that stores the information about students (name, student id,
// department, and address) in a structure and then transfers the information to
// a file in your directory. Finally, retrieve the information from your file
// and print it in the proper format on your output screen.

#include <fstream>
#include <iostream>
using namespace std;

class Student {
  int id;
  char name[20], department[20], address[20];

public:
  void getData() {
    cout << "Enter following information:\n";
    cout << "Name = ";
    cin >> name;
    cout << "Id = ";
    cin >> id;
    cout << "Department = ";
    cin >> department;
    cout << "Address = ";
    cin >> address;
  }
  void display() {
    cout << "\nStudent's Information: " << endl;
    cout << "Name = " << name << endl;
    cout << "Id = " << id << endl;
    cout << "Department = " << department << endl;
    cout << "Address = " << address << endl;
  }
};

void inputToFile() {
  fstream file("student.dat", ios::out | ios::binary);
  char choice;
  Student s;
  do {
    s.getData();
    file.write((char *)(&s), sizeof(s));
    cout << "Do you want to continue(y/n)? ";
    cin >> choice;
  } while (choice == 'y');
}

void outputToFile() {
  fstream file("student.dat", ios::in | ios::binary);
  Student s;
  file.read((char *)(&s), sizeof(s));
  while (!file.eof()) {
    s.display();
    file.read((char *)(&s), sizeof(s));
  }
}

int main() {
  inputToFile();
  outputToFile();
}