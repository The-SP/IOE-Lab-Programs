// Lab 9
// Question 3
// Modify the stack class given in the previous lab to add the exception when
// user tries to add item while the stack is full and when user tries to add
// item while the stack is empty. Throw exception in both of the cases and
// handle these exceptions.

#include <cstring>
#include <iostream>
#define SIZE 2
using namespace std;

class EXC {
public:
  string info;
};

template <class T> class Stack {
  T st[SIZE];
  int top;

public:
  Stack();
  void push(T var);
  T pop();
};

template <class T> Stack<T>::Stack() { top = -1; }

template <class T> void Stack<T>::push(T var) {
  try {
    if (top >= (SIZE - 1)) {
      top = SIZE - 1;
      EXC e;
      e.info = "Stack is full";
      throw e;
    } else {
      st[++top] = var;
    }
  } catch (EXC e) {
    cerr << e.info << endl;
  }
}

template <class t> t Stack<t>::pop() {
  try {
    if (top < 0) {
      EXC e;
      e.info = "stack is empty";
      throw e;
    } else {
      return st[top--];
    }
  } catch (EXC e) {
    cerr << e.info << endl;
  }
}

int main() {
  Stack<float> s1;

  s1.push(11.1f);
  s1.push(20.2f);
  s1.push(35.3f);

  cout << "1 : " << s1.pop() << endl;
  cout << "2 : " << s1.pop() << endl;
  cout << "3 : " << s1.pop() << endl;

  Stack<int> s2;
  s2.push(23);
  s2.push(3254);
  s2.push(69);

  cout << "1 : " << s2.pop() << endl;
  cout << "2 : " << s2.pop() << endl;
  cout << "3 : " << s2.pop() << endl;
}