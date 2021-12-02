// Lab 6
// Question 2
// Write two classes to store distances in meter-centimeter and feet-inch system respectively. Write conversions functions so that the program can convert objects of both types.

#include <iostream>
using namespace std;

#define FEET_TO_METER 0.3048f
#define METER_TO_FEET 3.28f

class Feet;

class Meter
{
    int m, cm;

public:
    Meter(float dist)
    {
        m = dist;
        cm = (dist - m) * 100;
    };
    Meter(int m1, int cm1) : m(m1), cm(cm1) {}

    operator Feet();

    void display()
    {
        cout << m << " m " << cm << " cm" << endl;
    }
};

class Feet
{
    int ft, inch;

public:
    Feet(float dist)
    {
        ft = dist;
        inch = (dist - ft) * 12;
    };
    Feet(int f, int i) : ft(f), inch(i) {}

    void display()
    {
        cout << ft << " ft " << inch << " inch" << endl;
    }

    operator Meter()
    {
        return Meter((ft + inch / 12.f) * FEET_TO_METER);
    }
};

Meter::operator Feet()
{
    return Feet((m + cm / 100.f) * METER_TO_FEET);
}

int main()
{
    cout << "Distance in Metric = ";
    Meter d(10.65f);
    d.display();
    cout << "Converting into Feet = ";
    Feet(d).display();
    cout << endl;
    cout << "Distance in Feet = ";
    Feet f(20.34);
    f.display();
    cout << "Converting into Metric = ";
    Meter(f).display();
}