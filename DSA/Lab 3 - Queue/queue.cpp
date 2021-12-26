#include <iostream>
using namespace std;
#define SIZE 100

template <class T>
class Queue {
    int front, rear;
    T arr[SIZE];

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(T x) {
        if (rear >= SIZE - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        arr[++rear] = x;
    }

    bool isEmpty() {
        return (front > rear);
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty";
            return -1;
        }
        return arr[front++];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "\nDisplaying items in the queue: \n";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << "\t";
        cout << endl;
    }
};

int main() {
    Queue<int> q;
    q.display();
    for (int i = 0; i < 5; i++)
        q.enqueue(i);
    cout << "\nEnqueue operations performed. \n";
    q.display();
    cout << "\nPerforming dequeue operations: ";
    while (!q.isEmpty())
        cout << q.dequeue() << ' ';
}