// Doubly linear linked list
#include <iostream>
using namespace std;

template <class T>
struct node {
    T info;
    node *next, *prev;

    node(T value) {
        next = prev = nullptr;
        info = value;
    }
};

template <class T>
class List {
    node<T> *head;

    node<T> *findNode(T data) {
        node<T> *i = head;
        while (i->info != data) {
            i = i->next;
            if (i == nullptr) {
                cout << "Invalid operation: Data " << data << " not found\n";
                exit(1);
            }
        }
        return i;
    }

public:
    List() {
        head = nullptr;
    }

    void insertBeginning(T x) {
        node<T> *ptr = new node<T>(x);
        ptr->next = head;
        if (head != nullptr)
            head->prev = ptr;
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
        node<T> *ptr = new node<T>(x);
        ptr->prev = i;
        i->next = ptr;
    }

    void insertAfter(T x, T after) {
        if (!head) {
            cout << "Invalid insertion: Empty list\n";
            return;
        }
        node<T> *i = findNode(after);
        node<T> *ptr = new node<T>(x);
        ptr->next = i->next;
        ptr->prev = i;
        i->next->prev = ptr;
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
        node<T> *i = findNode(before);
        node<T> *ptr = new node<T>(x);
        ptr->next = i;
        ptr->prev = i->prev;
        i->prev->next = ptr;
        i->prev = ptr;
    }

    void deleteBeginning() {
        if (!head) {
            cout << "Invalid deletion: Empty list\n";
            return;
        }
        node<T> *ptr = head;
        cout << "Deleted item = " << ptr->info << endl;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        delete ptr;
    }

    void deleteEnd() {
        if (!head) { // no node
            cout << "Invalid deletion: Empty list\n";
            return;
        } else if (head->next == nullptr) { // only one node
            deleteBeginning();
            return;
        }
        node<T> *ptr = head;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        cout << "Deleted item = " << ptr->info << endl;
        ptr->prev->next = nullptr;
        delete ptr;
    }

    void deleteAfter(T after) {
        if (!head) {
            cout << "Invalid deletion: Empty list\n";
            return;
        }
        node<T> *i = findNode(after);
        if (i->next == nullptr) {
            cout << "Invalid deletion: No node after element " << after << endl;
            return;
        }
        node<T> *ptr = i->next;
        cout << "Deleted item = " << ptr->info << endl;
        i->next = ptr->next;
        if (ptr->next != nullptr) ptr->next->prev = i;
        delete ptr;
    }

    void deleteBefore(T before) {
        if (!head) {
            cout << "Invalid deletion: Empty list\n";
            return;
        } else if (head->info == before) {
            cout << "Invalid deletion: No node before element " << before << endl;
            return;
        }
        node<T> *i = findNode(before);
        node<T> *ptr = i->prev;
        cout << "Deleted item = " << ptr->info << endl;
        i->prev = ptr->prev;
        if (ptr == head) // current head is deleted, so assign new head
            head = i;
        else // ptr->prev !- nullptr
            ptr->prev->next = i;
        delete ptr;
    }

    void display() {
        cout << "\nDisplaying items in a doubly linked list: ";
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
    list.insertEnd(60);
    list.display();
    list.deleteBeginning();
    list.deleteEnd();
    list.display();
    list.deleteBefore(30);
    list.deleteBefore(40);
    list.deleteAfter(30);
    list.display();
}