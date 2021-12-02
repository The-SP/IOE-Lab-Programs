// Lab 6
// Question 1
//  Write a program that can convert the Distance (meter, centimeter) to meters measurement in float and vice versa. Make a class distance with two data members, meter and centimeter. You can add function members as per your requirement.

#include <iostream>
using namespace std;

class Distance {
    int m, cm;

public:
    Distance(int m1, int cm1) {
        m = m1;
        cm = cm1;
    }
    
    Distance(float dis) {
        m = dis;
        cm = (dis-m)*100;
    }

    operator float() {
        return m + (cm/100.f);
    }

    void display() {
        cout << m << " m " << cm << " cm" << endl;
    }
};

int main() {
    Distance d(10, 75);
    cout << "Distance = ";
    d.display();
    cout << "Distance in float = " << d << " m\n";
    Distance d2(5.3);
    cout << "Float to m and cm measurement = ";
    d2.display();
}