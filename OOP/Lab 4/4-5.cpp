// Lab 4
// Question 5
/*
Write a program that illustrates the following relationship and comment on them. 
i) const_object.non_const_mem_function
ii) const_object.const_mem_function
iii) non_const_object.non_const_mem_function
iv) non_const_object.const_mem_function
*/

#include <iostream>
using namespace std;

class Relation
{
    const int id;

public:
    Relation(int i) : id(i) {}
    int get() { return id; }
    int const_get() const { return id; }
};

int main()
{
    Relation r(1);
    cout << "non const object calling non const mem func = " << r.get() << endl;   // non const object. non const mem func
    cout << "non const object calling const mem func = " << r.const_get() << endl; // non const object. const mem
    const Relation c(2);
    cout << "const object calling const mem func = " << c.const_get(); // const object.cont mem func
    // cout << c.get();  cannot be called
}