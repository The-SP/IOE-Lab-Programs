// Adding two polynomials using linked list

#include <iostream>
using namespace std;

template <class T>
struct node {
    T coeff;
    int exp;
    node *next;
};

template <class T>
class List {
    node<T> *head;

public:
    List() {
        head = nullptr;
    }

    node<T> *getHead() {
        return head;
    }

    // Inserting to sorted linked list
    void insert(T x, int power) {
        node<T> *ptr = new node<T>;
        ptr->coeff = x;
        ptr->exp = power;
        // If there is no node in the list OR given power is > than first node's exp insert to beginning
        if (head == nullptr || power > head->exp) {
            ptr->next = head;
            head = ptr;
        } else {
            node<T> *temp = head;
            // find correct position for node depending on power of x
            while (temp->next != nullptr && temp->next->exp > power)
                temp = temp->next;
            ptr->next = temp->next;
            temp->next = ptr;
        }
    }

    void display() {
        node<T> *temp = head;
        char sign;
        while (temp) {
            sign = (temp->coeff) < 0 ? '-' : '+';
            if (temp != head)
                cout << ' ' << sign << ' ' << abs(temp->coeff);
            else
                cout << temp->coeff;
            cout << "x^" << temp->exp;
            temp = temp->next;
        }
    }
};

template <class T>
List<T> addPolynomials(List<T> &l1, List<T> &l2) {
    List<T> sum;
    node<T> *a = l1.getHead(), *b = l2.getHead();
    while (a && b) {
        // If both powers are equal, then add the coeff and store it in the resultant polynomial
        if (a->exp == b->exp) {
            sum.insert(a->coeff + b->coeff, a->exp);
            a = a->next;
            b = b->next;
        }
        // If power of 1st polynomial is greater then 2nd,
        // then store 1st into the resultant and move its pointer
        else if (a->exp > b->exp) {
            sum.insert(a->coeff, a->exp);
            a = a->next;
        }
        // If power of 2nd polynomial is greater then 1st,
        // then store 2nd into the resultant and move its pointer
        else {
            sum.insert(b->coeff, b->exp);
            b = b->next;
        }
    }
    // If some terms remain in a or b, store them to resultant
    while (a) {
        sum.insert(a->coeff, a->exp);
        a = a->next;
    }
    while (b) {
        sum.insert(b->coeff, b->exp);
        b = b->next;
    }
    return sum;
}

int main() {
    List<int> l1, l2, ans;
    // Initializing polynomials
    // A = -3x4 + 5x3 - 4x + 2x0
    l1.insert(-4, 1);
    l1.insert(2, 0);
    l1.insert(-3, 4);
    l1.insert(5, 3);
    // B = -2x4 + 2x^1 - 5x^0
    l2.insert(2, 1);
    l2.insert(-5, 0);
    l2.insert(-2, 4);

    cout << "\n1st polynomial = \t";
    l1.display();
    cout << "\n2nd polynomial = \t";
    l2.display();
    cout << "\n\t\t\t-------------------------------------";
    cout << "\nSum of polynomials = \t";
    ans = addPolynomials(l1, l2);
    ans.display();
}