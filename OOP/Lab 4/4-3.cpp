// Lab 4
// Question 3
// Write a class that can store Department ID and Department Name with constructors to initialize its members. Write destructor member in the same class and display the message "Object n goes out of the scope". Your program should be made such that it should show the order of constructor and destructor invocation.

#include <iostream>
#include <cstring>
using namespace std;

class Department
{
    int id;
    char name[20];

public:
    Department(int i, const char* n)
    {
        id = i;
        strcpy(name, n);
        cout << "Object "<< name << " has been contructed"<< endl;
    }

    ~Department()
    {
        cout << "Object " << name << " goes out of scope.";
    }
};

int main()
{
    Department d(1, "Cyber");
}