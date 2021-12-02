// Lab 7
// Question 3
// Write a program with Student as abstract class and create derive classes
// Engineering, Medicine and Science from base class Student. Create the objects
// of the derived classes and process them and access them using array of
// pointer of type base class Student.

#include <cstring>
#include <iostream>
using namespace std;

class Student {
protected:
  int id;
  string name;

public:
  virtual int getId() = 0;
  virtual string getName() = 0;
};

class Engineering : public Student {
public:
  Engineering(int i, string n) {
    id = i;
    name = n;
  }
  int getId() { return id; }
  string getName() { return name; }
};

class Medicine : public Student {
public:
  Medicine(int i, string n) {
    id = i;
    name = n;
  }
  int getId() { return id; }
  string getName() { return name; }
};

class Science : public Student {
public:
  Science(int i, string n) {
    id = i;
    name = n;
  }
  int getId() { return id; }
  string getName() { return name; }
};

int main() {
  Student *ptr[3] = {new Engineering(1, "Levi"), new Medicine(2, "Eren"),
                     new Science(3, "Erwin")};
  cout << "Students of various fields: " << endl;
  for (int i = 0; i < 3; i++) {
    cout << "Name = " << ptr[i]->getName();
    cout << "\tId = " << ptr[i]->getId() << endl;
    delete ptr[i];
  }
}