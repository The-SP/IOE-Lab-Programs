// Lab 6
// Question 3
/*
Create a class called Musicians to contain three methods string ( ), wind ( ) and perc ( ). Each of these methods should initialize a string array to contain the following instruments
 -  veena, guitar, sitar, sarod and mandolin under string ( )
 -  flute, clarinet saxophone, nadhaswaram and piccolo under wind ( )
 -  tabla, mridangam, bangos, drums and tambour under perc ( )
 It should also display the contents of the arrays that are initialized. Create a derived class called TypeIns to contain a method called get ( ) and show ( ). The get ( ) method must display a  menu as follows
 Type of instruments to be displayed
 a. String instruments
 b. Wind instruments
 c. Percussion instruments
 The show ( ) method should display the relevant detail according to our choice. The base class variables must be accessible only to its derived classes
 */

#include <iostream>
#include <cstring>
using namespace std;

class Musicians
{
protected:
    string str[5];
    string wnd[5];
    string per[5];

public:
    void string()
    {
        str[0] = "vern";
        str[1] = "guitar";
        str[2] = "sitar";
        str[3] = "sarod";
        str[4] = "mandolin";
        cout << "string instrument has been initialized to" << std::endl;
        for (int i = 0; i < 5; i++)
        {
            cout << str[i] << std::endl;
        }
    }
    void wind()
    {
        wnd[0] = "flute";
        wnd[1] = "clarinet";
        wnd[2] = "saxophone";
        wnd[3] = "nadhaswaram";
        wnd[4] = "piccolo";
        cout << "wind instrument has been initialized to" << std::endl;
        for (int i = 0; i < 5; i++)
        {
            cout << wnd[i] << std::endl;
        }
    }
    void perc()
    {
        per[0] = "tabla";
        per[1] = "mridangam";
        per[2] = "bangos";
        per[3] = "drums";
        per[4] = "tambour";
        cout << "percussion instrument has been initialized to" << std::endl;
        for (int i = 0; i < 5; i++)
        {
            cout << per[i] << std::endl;
        }
    }
};

class TypeIns : public Musicians
{
public:
    void get()
    {
        cout << endl;
        cout << "Type of instrument to be displayed" << std::endl;
        cout << "a. String instruments" << std::endl;
        cout << "b. Wind instruments" << std::endl;
        cout << "c. Percussion instruments" << std::endl;
        char choice;
        std::cout << "Choice? ";
        std::cin >> choice;
        show(choice);
    }

    void show(char choice)
    {
        if (choice == 'a')
            for (int i = 0; i < 5; i++)
                cout << str[i] << std::endl;
        else if (choice == 'b')
            for (int i = 0; i < 5; i++)
                cout << wnd[i] << std::endl;
        else if (choice == 'c')
            for (int i = 0; i < 5; i++)
                cout << per[i] << std::endl;
        else
            cout << "Invalid choice";
    }
};

int main()
{
    TypeIns t;
    t.string();
    t.perc();
    t.wind();
    t.get();
}