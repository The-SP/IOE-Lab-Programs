// Stack implementation using linked list
#include <iostream>
using namespace std;

template <class T>
struct node {
    T info;
    node *next;
};

template <class T>
class Stack {
    node<T> *top;

public:
    Stack() {
        top = nullptr;
    }

    void push(T x) {
        node<T> *ptr = new node<T>;
        ptr->info = x;
        ptr->next = top;
        top = ptr;
    }

    void pop() {
        if (!top) {
            cout << "Invalid deletion: Empty stack\n";
            return;
        }
        node<T> *ptr = top;
        cout << "Deleted item = " << ptr->info << endl;
        top = top->next;
        delete ptr;
    }

    void display() {
        cout << "\nDisplaying items in a stack: ";
        if (!top) {
            cout << "Empty stack\n";
            return;
        }
        node<T> *i = top;
        while (i) {
            cout << i->info << ' ';
            i = i->next;
        }
        cout << "\n\n";
    }
};

int main() {
    Stack<int> stack;
    for (int i = 0; i < 10; i++)
        stack.push(i * 10);
    stack.display();
    for (int i = 0; i < 5; i++)
        stack.pop();
    stack.display();
}