// Lab 7
// Question 1
// Write a program to create a class shape with functions to find area of the
// shapes and display the name of the shape and other essential component of the
// class. Create derived classes circle, rectangle and trapezoid each having
// overridden functions area and display. Write a suitable program to illustrate
// virtual functions and virtual destructor.

#include <cstring>
#include <iostream>
using namespace std;

#define PI 3.14f

class Shape {
protected:
  char name[20];
  float shapeArea;

public:
  Shape(const char *sname) {
    strcpy(name, sname);
    shapeArea = 0;
  }
  virtual void area() { cout << "Area = " << shapeArea << endl; }
  virtual void display() = 0;
  virtual ~Shape() { cout << "Shape Destructor\n\n"; }
};

class Circle : public Shape {
  float r;

public:
  Circle(float a, const char *name) : Shape(name), r(a) {}
  void area() {
    shapeArea = PI * r * r;
    Shape::area();
  }
  void display() { cout << "Shape = Circle " << name << endl; }
  ~Circle() { cout << "Circle destructor" << endl; }
};

class Rectangle : public Shape {
  float l, b;

public:
  Rectangle(float x, float y, const char *name) : Shape(name), l(x), b(y) {}
  void area() {
    shapeArea = l * b;
    Shape::area();
  }
  void display() { cout << "Shape = Rectangle " << name << endl; }
  ~Rectangle() { cout << "Rectangle destructor" << endl; }
};

class Trapezoid : public Shape {
  float parallelSide[2];
  float nonParallelSide[2];

public:
  Trapezoid(float a1, float a2, float b1, float b2, const char *name)
      : Shape(name) {
    parallelSide[0] = a1;
    parallelSide[1] = a2;
    nonParallelSide[0] = b1;
    nonParallelSide[1] = b2;
  }
  void area() {
    shapeArea = (parallelSide[0] + parallelSide[1]) / 2.0 *
                (nonParallelSide[0] + nonParallelSide[1]) / 2.0;
    Shape::area();
  }
  void display() { cout << "Shape = Trapezoid " << name << endl; }
  ~Trapezoid() { cout << "Trapezoid destructor" << endl; }
};

int main() {
  Shape *shape = new Circle(2, "Ball");
  shape->display();
  shape->area();
  delete (shape);

  shape = new Rectangle(2, 5, "Ground");
  shape->display();
  shape->area();
  delete (shape);

  shape = new Trapezoid(2, 3, 5, 6, "Stadium");
  shape->display();
  shape->area();
  delete (shape);
}