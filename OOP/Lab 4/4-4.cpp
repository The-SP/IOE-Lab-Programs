// Lab 4
// Question 4
// Assume that one constructor initializes data member say num_vehicle, hour, and rate. There should be a 10% discount if num_vehicle exceeds 10. Display the total charge. Use two objects and show a bit-by-bit copy of one object to another (make your own copy constructor).

#include <iostream>
using namespace std;

class Vehicle
{
    int num_vehicle;
    float hour, rate;

public:
    Vehicle(int n, float h, float r) : num_vehicle(n), hour(h), rate(r) {
        cout << "Object constructed using constructor" << endl;
    }

    int getNum() { return num_vehicle; }
    float getHour() { return hour; }
    float getRate() { return rate; }

    Vehicle(Vehicle &v)
    {
        num_vehicle = v.getNum();
        hour = v.getHour();
        rate = v.getRate();
        cout << "Object constuced using copy constructor" << endl;
    }

    float totalCharge()
    {
        float total = num_vehicle * hour * rate;
        if (num_vehicle > 10)
            total = total - 0.1f * total;
        return total;
    }

    void display()
    {
        cout << "No of vehicle = " << num_vehicle << endl;
        cout << "No of hours = " << hour << endl;
        cout << "Rate = " << rate << endl;
        cout << "Total = " << totalCharge() << endl;
    }
};

int main()
{
    Vehicle v1(5, 2.5, 100);
    v1.display();
    cout << endl;
    Vehicle v2(v1); // v2 = v1
    v2.display();
}