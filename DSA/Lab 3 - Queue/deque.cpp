#include <iostream>
using namespace std;
#define SIZE 10

template <class T>
class Deque {
    int f, r;
    T arr[SIZE];

public:
    Deque() {
        f = r = -1;
    }

    bool isEmpty() {
        return (f == -1 && r == -1);
    }

    bool isFull() {
        return (f == r + 1) || ((f == 0) && (r == SIZE - 1));
    }

    void addFront(T x) {
        if (isFull()) {
            cout << "Overflow \n";
            return;
        }
        if ((f == -1) && (r == -1))
            f = r = 0;
        else if (f == 0)
            f = SIZE - 1;
        else
            f--;
        arr[f] = x;
        cout << "Add " << x << " at front=" << f << endl;
    }

    void addRear(T x) {
        if (isFull()) {
            cout << "Overflow \n";
            return;
        }
        if ((f == -1) && (r == -1))
            f = r = 0;
        else if (r == SIZE - 1)
            r = 0;
        else
            r++;
        arr[r] = x;
        cout << "Add " << x << " at rear=" << r << endl;
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "Underflow";
            return;
        }
        T item = arr[f];
        if (f == r) {
            f = -1;
            r = -1;
        } else if (f == (SIZE - 1))
            f = 0;
        else
            f++;
        cout << "The deleted item = " << item << endl;
    }

    void removeRear() {
        if (isEmpty()) {
            cout << "Underflow";
            return;
        }
        T item = arr[r];
        if (f == r) {
            f = -1;
            r = -1;
        } else if (r == 0)
            r = SIZE - 1;
        else
            r--;
        cout << "The deleted item = " << item << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "\nDeque is empty\n";
            return;
        }
        cout << "\nDisplaying elements in deque: ";
        int i = f;
        for (; i != r; i = (i + 1) % SIZE)
            cout << arr[i] << ' ';
        cout << arr[i] << endl;
    }
};

int main() {
    Deque<int> q;
    q.display();
    int i = 0;
    for (; i < 5; i++)
        q.addFront(i);
    for (; i < 10; i++)
        q.addRear(i);
    q.display();
    q.addFront(404);
    q.removeFront();
    q.removeRear();
    q.addFront(404);
    q.display();
}