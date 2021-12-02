// Lab 4
// Question 1
// Write a program that has a class to represent time. The class should have constructors to initialize data members hour, minute and second to 0 and to initialize them to values passed as arguments. The class should have member function to add time objects and return the result as time object. There should be another function to display the result in 24 hour format.

#include <iostream>
using namespace std;

class Time
{
    int hr, min, sec;

public:
    Time(): hr(0), min(0), sec(0){}

    Time(int h, int m, int s)
    {
        hr = h;
        min = m;
        sec = s;
    }

    Time add(Time &t)
    {
        Time ans;
        ans.sec = sec + t.sec;
        ans.min = min + t.min;
        ans.hr = hr + t.hr;
        if (ans.sec > 60)
        {
            ans.min += ans.sec / 60;
            ans.sec %= 60;
        }
        if (ans.min > 60)
        {
            ans.hr += ans.min / 60;
            ans.min %= 60;
        }
        return ans;
    }

    void display12()
    {
        cout << "\nTime in 12 hour format = ";
        if (hr > 12)
            cout << hr%12 << ":" << min << ":" << sec << " PM";
        else    
            cout << hr << ":" << min << ":" << sec << " AM";
    }

    void display24()
    {
        cout << "\nTime in 24 hour format = "
             << hr << ":" << min << ":" << sec;
    }
};

int main()
{
    int hr, min, sec;
    cout << "Enter time in hr, min and sec: ";
    cin >> hr >> min >> sec;
    Time t1(hr, min, sec);
    cout << "Enter time in hr, min and sec: ";
    cin >> hr >> min >> sec;
    Time t2(hr, min, sec);
    Time ans = t1.add(t2);
    ans.display12();
    ans.display24();
}
