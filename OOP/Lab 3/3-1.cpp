// Lab 3
// Question 1
// Write a simple program that converts the temperature in Celsius scale to Fahrenheit scale and vice versa using the basic concept of class and object. Make separate classes for Celsius and Fahrenheit which will have the private members that hold the temperature value and make conversion functions in each class for conversion from one to another. For example, you need to have a function toFahrenheit() in class Celsius that converts to Fahrenheit scale and returns the value.


#include <iostream>
using namespace std;

class Celsius {
    float temp;
public:
    Celsius(float t) {
        temp = t;
    }
    float toFahrenheit() {
        return temp * (9/5.f) + 32;
    }
};

class Fahrenheit {
    float temp;
public:
    Fahrenheit(float t) {
        temp = t;
    }
    float toCelsius() {
        return (temp-32) * (5/9.f);
    }
};

int main() {
    float t1, t2;
    cout << "Enter temperature in celsius? ";
    cin >> t1;
    cout << "Enter temperature in fahrenheit? ";
    cin >> t2;   
    Celsius c(t1);
    Fahrenheit f(t2);
    cout << endl;
    cout << t1 << " deg Celsius = " << c.toFahrenheit() << " deg Fahrenheit\n";
    cout << t2 << " deg Fahrenheit = " << f.toCelsius() << " deg Celsius";
}