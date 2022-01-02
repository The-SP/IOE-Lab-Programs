#include <iostream>
using namespace std;
#define MAXSIZE 50

template <class T>
struct node {
    T info;
    int next;
};

template <class T>
class List {
    node<T> node[MAXSIZE];
    int avail, start;
    // avail points to the available node and start points to the first node of the created list

    //initial ordering the array of nodes so that each points to the consecutive node
    void initialOrdering() {
        for (int i = 0; i < MAXSIZE - 1; i++)
            node[i].next = i + 1;
        node[MAXSIZE - 1].next = -1;
    }

    int getNode() {
        if (avail == -1) {
            cout << "Overflow";
            exit(1);
        }
        int p = avail;
        avail = node[avail].next;
        return p;
    }

    void freeNode(int p) {
        node[p].next = avail;
        avail = p;
    }

    // this function finds the index of the node containing the reference data
    int findIndex(T data) {
        int i = start;
        while (i != -1) { // i=-1 indicates end of list
            if (node[i].info == data)
                break;
            i = node[i].next;
        }
        return i;
    }

public:
    List() {
        initialOrdering();
        avail = 0;
        start = -1;
    }

    void insertBeginning(T x) {
        int q = getNode();
        node[q].info = x;
        node[q].next = start;
        start = q;
    }

    void insertEnd(T x) {
        if (start == -1) {
            insertBeginning(x);
            return;
        }
        int q = getNode();
        node[q].info = x;
        node[q].next = -1;
        int i = start;
        while (node[i].next != -1)
            i = node[i].next;
        node[i].next = q;
    }

    void insertAfter(T data, T x) {
        if (start == -1) {
            cout << "Invalid insertion: Empty list\n";
            return;
        }
        int i, q;
        i = findIndex(data);
        if (i == -1) {
            cout << "Invalid insertion: Element not found\n";
            return;
        }
        q = getNode();
        node[q].info = x;
        node[q].next = node[i].next;
        node[i].next = q; 
    }

    void deleteAfter(T data) {
        int q, i;
        i = findIndex(data);
        if (i == -1 || node[i].next == -1) {
            cout << "Invalid deletion\n";
            return;
        }
        q = node[i].next;
        cout << "Deleted item = " << node[q].info << endl;
        node[i].next = node[q].next;
        freeNode(q);
    }

    void deleteBeginning() {
        if (start == -1) {
            cout << "Empty list\n";
            return;
        }
        int q = start;
        cout << "Deleted item from beginning = " << node[q].info << endl;
        start = node[start].next;
        freeNode(q);
    }

    void deleteEnd() {
        if (start == -1) {
            cout << "Empty list\n";
            return;
        } else if (node[start].next == -1) { // only one node in list
            cout << "Deleted item from the end = " << node[start].info << endl;
            freeNode(start);
            start = -1;
            return;
        }
        int newEnd, i = start;
        while (node[i].next != -1) {
            newEnd = i;
            i = node[i].next;
        }
        cout << "Deleted item from the end = " << node[i].info << endl;
        freeNode(i);
        node[newEnd].next = -1;
    }

    void display() {
        cout << "\nDisplaying nodes: ";
        if (start == -1) {
            cout << "Empty list\n";
            return;
        }
        int i = start;
        while (i != -1) {
            cout << node[i].info << ' ';
            i = node[i].next;
        }
        cout << "\n\n";
    }
};

int main() {
    List<int> list;
    int choice, input, ref_element;
    cout << "Static List:\n";
    cout << "1. Insert at beginning\n"
         << "2. Insert at end\n"
         << "3. Insert after specific node\n"
         << "4. Delete from beginning\n"
         << "5. Delete from end\n"
         << "6. Delete after specific node\n"
         << "7. Exit\n";
    while (1) {
        cout << "Enter the operation to perform? ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter the element to insert :";
            cin >> input;
            list.insertBeginning(input);
            break;
        case 2:
            cout << "Enter the element to insert :";
            cin >> input;
            list.insertEnd(input);
            break;
        case 3:
            cout << "Enter the element to insert :";
            cin >> input;
            cout << "Enter after which element to insert :";
            cin >> ref_element;
            list.insertAfter(ref_element, input);
            break;
        case 4:
            list.deleteBeginning();
            break;
        case 5:
            list.deleteEnd();
            break;
        case 6:
            cout << "Enter after which element to delete : ";
            cin >> ref_element;
            list.deleteAfter(ref_element);
            break;
        case 7:
            cout << "\nYou pressed exit";
            exit(1);
        default:
            cout << "Invalid choice.";
            break;
        }
        list.display();
    }
}