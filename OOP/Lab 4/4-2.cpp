// Lab 4
// Question 2
// Write a program that has a class with a dynamically allocated character array as its data member. One object should contain "Engineers are" and another should contain " Creatures of logic". Member function join() should concatenate two strings by passing two objects as arguments. Display the concatenated string through a member function. Use constructors to allocate and initialize the data member. Also, write a destructor to free the allocated memory for the character array. Make your own function for the concatenation of two strings.

#include <iostream>
using namespace std;

class String
{
    char *str;

    int str_length(char *s)
    {
        char *ptr = s;
        while (*ptr++ != '\0')
            ;
        return ptr - s;
    }

    void str_copy(char *destination, char *source)
    {
        while ((*destination++ = *source++) != '\0')
            ;
    }

    void str_concatenate(char *destination, char *a, char *b)
    {
        while (*a != '\0')
            *destination++ = *a++;
        while (*b != '\0')
            *destination++ = *b++;
        *destination = '\0';
    }

public:
    String() : str(NULL) {}

    String(char *s)
    {
        int size = str_length(s);
        str = new char[size];
        str_copy(str, s);
    }

    char *get() { return str; }

    void join(const String &a, const String &b)
    {
        int size = str_length(a.str) + str_length(b.str);
        if (str != NULL)
        {
            delete[] str;
            str = NULL;
        }
        this->str = new char[size];
        str_concatenate(str, a.str, b.str);
    }

    ~String()
    {
        delete[] str;
    }
};

int main()
{
    String a((char *)"Engineers are"), b((char *)" creatures of logic");
    cout << "a = " << a.get() << endl;
    cout << "b = " << b.get() << endl;

    String c;
    c.join(a, b);
    cout << "c = " << c.get();
}