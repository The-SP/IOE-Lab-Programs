// Lab 5
// Question 4
// Write a class Date that overloads prefix and postfix operators to increase day by one of the Date objects, while causing appropriate increments to the month and year (use the appropriate condition for leap year). The prefix and postfix operators in the Date class should behave exactly like the built-in increment operators.

#include <iostream>
using namespace std;

int days_in_months[] = {30, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date
{
    int y, m, d;

public:
    Date(int sy, int sm, int sd) : y(sy), m(sm), d(sd) {}

    Date operator++()
    {
        d++;
        if (d > days_in_months[m - 1])
        {
            if (m == 2 && ((y % 4) == 0) && ((y % 100) != 0 || (y % 400) == 0))
            {
                if (d > 29)
                {
                    m++;
                    d = 1;
                }
            }
            else
            {
                d = 1;
                m++;
                if (m > 12)
                {
                    m = 1;
                    y++;
                }
            }
        }
        return *this;
    }

    Date operator++(int)
    {
        Date temp = *this;
        ++(*this);
        return temp;
    }

    friend ostream &operator<<(ostream &stream, const Date &d)
    {
        cout << d.y << "/" << d.m << "/" << d.d << endl;
        return stream;
    }
};

int main()
{
    Date date(2020, 12, 30);
    cout << "date = " << date;
    cout << "++date = " << ++date;
    cout << "date++ = " << date++;
    cout << "date after post increment execution = " << date;
}