// Singly linear linked list
#include <iostream>
using namespace std;

template <class T>
struct node {
    T info;
    node *next;
};

template <class T>
class List {
    node<T> *head;

public:
    List() {
        head = nullptr;
    }

    void insertBeginning(T x) {
        node<T> *ptr = new node<T>;
        ptr->info = x;
        ptr->next = head;
        head = ptr;
    }

    void insertEnd(T x) {
        if (!head) { // Empty list
            insertBeginning(x);
            return;
        }
        node<T> *i = head;
        while (i->next != nullptr)
            i = i->next;
        node<T> *ptr = new node<T>;
        i->next = ptr;
        ptr->info = x;
        ptr->next = nullptr;
    }

    void insertAfter(T x, T after) {
        if (!head) {
            cout << "Invalid insertion: Empty list\n";
            return;
        }
        node<T> *i = head;
        while (i->info != after) {
            i = i->next;
            if (!i) {
                cout << "Invalid insertion: Element " << after << " not found\n";
                return;
            }
        }
        node<T> *ptr = new node<T>;
        ptr->info = x;
        ptr->next = i->next;
        i->next = ptr;
    }

    void insertBefore(T x, T before) {
        if (!head) {
            cout << "Invalid insertion: Empty list\n";
            return;
        } else if (head->info == before) {
            insertBeginning(x);
            return;
        }
        node<T> *i, *prev;
        i = head;
        while (i->info != before) {
            prev = i;
            i = i->next;
            if (!i) {
                cout << "Invalid insertion: Element " << before << "  not found\n";
                return;
            }
        }
        node<T> *ptr = new node<T>;
        ptr->info = x;
        ptr->next = i;
        prev->next = ptr;
    }

    void deleteBeginning() {
        if (!head) {
            cout << "Invalid deletion: Empty list\n";
            return;
        }
        node<T> *ptr = head;
        cout << "Deleted item = " << ptr->info << endl;
        head = head->next;
        delete ptr;
    }

    void deleteEnd() {
        if (!head) {    // no node
            cout << "Invalid deletion: Empty list\n";
            return;
        } else if (!head->next) {   // only one node
            deleteBeginning();
            return;
        }
        node<T> *prev, *ptr = head;
        while (ptr->next) {
            prev = ptr;
            ptr = ptr->next;
        }
        cout << "Deleted item = " << ptr->info << endl;
        prev->next = nullptr;
        delete ptr;
    }

    void deleteAfter(T after) {
        if (!head) {
            cout << "Invalid deletion: Empty list\n";
            return;
        }
        node<T> *i = head;
        while (i->info != after) {
            i = i->next;
            if (!i) {
                cout << "Invalid deletion: Element " << after << " not found\n";
                return;
            }
        }
        if (!i->next) {
            cout << "Invalid deletion: No node after element " << after << endl;
            return;
        }
        node<T> *ptr = i->next;
        cout << "Deleted item = " << ptr->info << endl;
        i->next = ptr->next;
        delete ptr;
    }

    void display() {
        cout << "\nDisplaying items in a linear linked list: ";
        if (!head) {
            cout << "Empty list\n";
            return;
        }
        node<T> *i = head;
        while (i) {
            cout << i->info << ' ';
            i = i->next;
        }
        cout << "\n\n";
    }
};

int main() {
    List<int> list;
    list.insertBeginning(10);
    list.insertBeginning(20);
    list.insertEnd(40);
    list.insertAfter(30, 20);
    list.insertBefore(50, 40);
    list.display();
    list.deleteBeginning();
    list.deleteEnd();
    list.deleteAfter(30);
    list.display();
}