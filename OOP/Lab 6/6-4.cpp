// Lab 6
// Question 4
// Write three derived classes inheriting functionality of base class person (should have a member function that asks to enter name and age) and with added unique features of student, and employee, and functionality to assign, change and delete records of student and employee. And make one member function for printing the address of the objects of classes (base and derived) using this pointer. Create two objects of the base class and derived classes each and print the addresses of individual objects. Using a calculator, calculate the address space occupied by each object and verify this with address spaces printed by the program.

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
protected:
    char name[20];
    int age;

public:
    void setName()
    {
        cout << "Enter name: ";
        cin >> name;
    }
    void setAge()
    {
        cout << "Enter age: ";
        cin >> age;
    }
    void set()
    {
        setName();
        setAge();
    }

    Person *getAddress()
    {
        return this;
    }
};

class Student : public Person
{
    int roll;

public:
    void setRoll(int r)
    {
        roll = r;
    }
};

class Employee : public Person
{
    int salary;
    char department[20];

public:
    void setSalary(int s)
    {
        salary = s;
    }
    void setDepartment(const char *str)
    {
        strcpy(department, str);
    }
};

int main()
{
    Person p1, p2;
    Employee e1, e2;
    Student s1, s2;
    cout << "&p1 = " << p1.getAddress() << "\t&p2 = " << p2.getAddress() << endl;
    cout << "Size of Person Object = " << sizeof(p1) << endl << endl;
    // cout << &p2 - &p1 << endl;
    cout << "&e1 = " << e1.getAddress() << "\t&e2 = " << e2.getAddress() << endl;
    cout << "Size of Employee Object = " << sizeof(e1) << endl << endl;
    // cout << &e2 - &e1 << endl;
    cout << "&s1 = " << s1.getAddress() << "\t&s2 = " << s2.getAddress() << endl;
    cout << "Size of Student Object = " << sizeof(s1) << endl;
    // cout << &s2 - &s1 << endl;
}