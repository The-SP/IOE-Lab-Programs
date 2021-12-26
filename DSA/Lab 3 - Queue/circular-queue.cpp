#include <iostream>
using namespace std;
#define SIZE 10

template <class T>
class Queue {
    int front, rear;
    T arr[SIZE];

public:
    Queue() {
        front = rear = 0;
    }

    void enqueue(T x) {
        if (front == (rear + 1) % SIZE) {
            cout << "Queue is full" << endl;
            return;
        }
        arr[rear] = x;
        // cout << "Inserting " << x << " at rear=" << rear << endl;
        rear = (rear + 1) % SIZE;
    }

    bool isEmpty() {
        return front == rear;
    }
    bool isFull() {
        return front == (rear + 1) % SIZE;
    }

    T dequeue() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            exit(0);
        }
        T item = arr[front];
        front = (front + 1) % SIZE;
        return item;
    }

    void display() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "\nDisplaying items in the circular queue: ";
        for (int i = front; i != rear; i = (i + 1) % SIZE)
            cout << arr[i] << ' ';
        cout << endl;
    }

    // display from index 0 to last
    void show() {
        for (int i = 0; i < SIZE; i++)
            cout << arr[i] << ' ';
    }
};

int main() {
    Queue<int> q;
    q.display();
    for (int i = 0; i < SIZE; i++)
        q.enqueue(i+10);
    q.display();
    cout << "Performing dequeue operations: ";
    while (!q.isEmpty())
        cout << q.dequeue() << ' ';
    
    // For convenience, we initialize rear=front for empty queue
    // In this circular array, one position is left vacant
}