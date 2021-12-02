// Lab 9
// Question 2
// Write a class template for queue class. Assume the programmer using the queue
// won't make mistakes, like exceeding the capacity of the queue, or trying to
// remove an item when the queue is empty. Define several queues of different
// data types and insert and remove data from them.

#include <iostream>
using namespace std;

template <typename T> class Queue {
private:
  T data[100] = {0};
  int pos = 0;

public:
  void add(T d) {
    cout << "Inserting " << d << endl;
    data[pos] = d;
    pos++;
  }
  T get() {
    T d = data[0];
    for (int i = 0; i < pos; i++)
      data[i] = data[i + 1];
    pos--;
    cout << "Removing " << d << endl;
    return d;
  }
};

int main() {
  Queue<int> intList;
  intList.add(5);
  intList.add(7);
  cout << intList.get() << endl;
  cout << intList.get() << endl;
  cout << endl;
  Queue<float> fList;
  fList.add(1.3);
  fList.add(4.9);
  cout << fList.get() << endl;
  cout << fList.get() << endl;
}