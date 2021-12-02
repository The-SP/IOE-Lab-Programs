// Lab 7
// Question 4
// Create a polymorphic class Vehicle and create other derived classes Bus, Car
// and Bike from Vehicle. With this program illustrate RTTI by the use of
// dynamic_cast and typeid operators.

#include <iostream>
using namespace std;

class Vehicle {
protected:
  int noOfWheels;

public:
  Vehicle() {}
  Vehicle(int n) : noOfWheels(n) {}
  virtual void display() { cout << "Vehicle display called" << endl; }
};

class Bus : public Vehicle {
public:
  Bus() : Vehicle(4) {}
  void display() { cout << "Bus display called" << endl; }
};

class Car : public Vehicle {
public:
  Car() : Vehicle(4) {}
  void display() { cout << "Car display called" << endl; }
};

class Bike : public Vehicle {
public:
  Bike() : Vehicle(2) {}
  void display() { cout << "Bike display called" << endl; }
};

int main() {
  Vehicle v1;
  cout << "Initially typeid = " << typeid(v1).name() << "\n\n";

    Vehicle *v[] = {new Bus(), new Car(), new Bike()};
    for (int i = 0; i < 3; i++) {
      cout << typeid(*v[i]).name() << endl;
      v[i]->display();
    }

    cout << "\nUsing dynamic_cast to cast from base class pointer to derived class pointer:\n";
    Bus *bus = dynamic_cast<Bus *>(v[0]);
    Car *car = dynamic_cast<Car *>(v[1]);
    Bike *bike = dynamic_cast<Bike *>(v[2]);
    cout << typeid(*bus).name() << endl;
    cout << typeid(*car).name() << endl;
    cout << typeid(*bike).name() << endl;
}