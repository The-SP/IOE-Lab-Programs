// Lab 3
// Question 3
// Create a class called carpark that has int data member for car id, int data member for charge/hour, and float data member for the parked time. Make functions to set data members and show the charges and parked hours of the corresponding car id. Make functions for setting and showing the data members. Member function should be called from other functions.

#include <iostream>
using namespace std;

class Carpark {
    int id, charge;
    float time;

    int getId() {return id;}
    int getCharge() {return charge;}
    float getTime() {return time;}
    float getTotalCharge() {return time*charge;}

public:
    void setId(int i) {id = i;}
    void setCharge(int c) {charge = c;}
    void setTime(float t) {time = t;}

    void display() {
        cout << "Id = " << getId();
        cout << "\nCharge/hour = " << getCharge();
        cout << "\nParked Time = " << getTime();
        cout << "\nTotal Charge = " << getTotalCharge();
    }
};


int main() {
    Carpark park; 
    int id, charge;
    float time;
    cout << "Enter car id? ";
    cin >> id;
    cout << "Enter charge per hour? ";
    cin >> charge;
    cout << "Enter time parked? ";
    cin >> time;

    // set
    park.setId(id);
    park.setCharge(charge);
    park.setTime(time);
    park.display();
}