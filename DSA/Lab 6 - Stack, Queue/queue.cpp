// Queue implementation using linked list
#include <iostream>
using namespace std;

template <class T>
struct node {
    T info;
    node *next;
};

template <class T>
class Queue {
    node<T> *front, *rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(T x) {         // like insertEnd() of linked list
        node<T> *ptr = new node<T>;
        ptr->info = x;
        ptr->next = nullptr;
        if (!rear) {
            // If queue is empty, set both front and rear as newnode
            front = rear = ptr;
        } else {
            // Add new node at end of queue and change rear
            rear->next = ptr;
            rear = ptr;
        }
    }

    void dequeue() {    // like deleteBeginning() of linked list
        if (!front) {
            cout << "Invalid deletion: Empty Queue\n";
        }else {
            node<T> *ptr = front;
            cout << "Deleted item = " << ptr->info << endl;
            front = front->next;
            delete ptr;
            
            // If only one element present at queue and it is removed, then
            // front becomes null so change rear also as null (i.e empty queue condition)
            if (front == nullptr)
                rear = nullptr;
        }
    }

    void display() {
        cout << "\nDisplaying items in a queue: ";
        if (!front) {
            cout << "Empty queue\n";
            return;
        }
        node<T> *i = front;
        while (i) {
            cout << i->info << ' ';
            i = i->next;
        }
        cout << "\n\n";
    }
};

int main() {
    Queue<int> q;
    q.enqueue(7);
    q.dequeue();
    q.dequeue();

    for (int i = 0; i < 10; i++)
        q.enqueue(i * 10);
    q.display();
    for (int i = 0; i < 5; i++)
        q.dequeue();
    q.display();
}