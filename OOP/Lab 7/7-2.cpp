// Lab 7
// Question 2
// Create a class Person and two derived classes Employee, and Student,
// inherited from class Person. Now create a class Manager which is derived from
// two base classes Employee and Student. Show the use of the virtual base
// class.

#include <cstring>
#include <iostream>
using namespace std;

class Person {
  string name;

public:
  Person(string n) { name = n; }
  void displayName() { cout << "Name = " << name << endl;}
};

class Employee : virtual public Person {
  int salary;

public:
  Employee(string name, int s) : Person(name), salary(s) {}
  int getSalary() { return salary; }
};

class Student : virtual public Person {
  int roll;

public:
  Student(string name, int r) : Person(name), roll(r) {}
  int getRoll() { return roll; }
};

class Manager : public Employee, public Student {
public:
  Manager(const char *name, int r, int s)
      : Employee(name, s), Student(name, r), Person(name) {}
};

int main() {
  Manager m("Elon Musk", 1, 100000);
  m.displayName();
  cout << "Students Roll = " << m.getRoll() << endl;
  cout << "Employee salary = " << m.getSalary() << endl;
}