// Lab 8
// Question 5
// Write a program for transaction processing that write and read object
// randomly to and from a random access file so that user can add, update,
// delete and display the account information (account-number, last-name,
// first-name, total-balance).

#include <fstream>
#include <iostream>
#define SUCCESS 0
using namespace std;

class Transaction {
  char firstName[20], lastName[20];
  int id, balance;

public:
  friend istream &operator>>(istream &in, Transaction &t) {
    cout << "------------------------------------------" << endl;
    cout << "First Name: ";
    in >> t.firstName;
    cout << "Last Name: ";
    in >> t.lastName;
    cout << "Account Number: ";
    in >> t.id;
    cout << "Total Balance: ";
    in >> t.balance;
    cout << "------------------------------------------" << endl;
    return in;
  }

  friend ostream &operator<<(ostream &out, Transaction t) {
    cout << "------------------------------------------" << endl;
    out << "First Name: " << t.firstName << endl;
    out << "Last Name: " << t.lastName << endl;
    out << "Account Number: " << t.id << endl;
    out << "Total Balance: " << t.balance << endl;
    cout << "------------------------------------------" << endl;
    return out;
  }

  static void createRecord() {
    char ans;
    fstream file("account.dat", ios::out | ios::binary);
    do {
      Transaction t;
      cin >> t;
      file.write((char*)&t, sizeof(t));
      cout << "Do you want to continue y/n ?  ";
      cin >> ans;
    } while (ans == 'y');
    file.close();
  }

  static void addRecord() {
    char ans;
    fstream file("account.dat", ios::out | ios::app | ios::binary);
    do {
      Transaction t;
      cin >> t;
      file.write((char*)&t, sizeof(t));
      cout << "Do you want to continue y/n ?  ";
      cin >> ans;
    } while (ans == 'y');
    file.close();
  }

  static void deleteRecord() {
    char choice;
    Transaction t;
    fstream file("account.dat", ios::in | ios::binary);
    fstream newFile("tmp.dat", ios::out | ios::binary);
    while (!file.eof()) {
      file.read((char*)&t, sizeof(t));
      if (file) {
        cout << t;
        cout << "Do you want to delete this record y/n ?  ";
        cin >> choice;
        if (choice != 'y')
          newFile.write((char*)&t, sizeof(t));
        else
          cout << "Record deleted" << endl;
      }
    }
    file.close();
    newFile.close();
    remove("account.dat");
    rename("tmp.dat", "account.dat");
  }

  static void editRecord() {
    char ans;
    fstream file("account.dat", ios::in | ios::binary | ios::out);
    while (!file.eof()) {
      Transaction t;
      int pos = file.tellg();
      file.read((char*)&t, sizeof(t));
      if (file) {
        cout << t;
        cout << "Do you want to edit this record y/n ? ";
        cin >> ans;
        if (ans == 'y') {
          cin >> t;
          file.seekp(pos);
          file.write((char*)&t, sizeof(t));
          cout << "Record sucessfully edited" << endl;
        }
      }
    }
    file.close();
  }

  static void displayRecord() {
    fstream file("account.dat", ios::in | ios::binary);
    while (1) {
      Transaction t;
      file.read((char*)&t, sizeof(t));
      if (file.eof()) break;
      cout << t;
    }
    file.close();
  }
};

int main() {
  int choice;
  do {
    cout << "Menu" << endl;
    cout << "1. create record" << endl;
    cout << "2. add record" << endl;
    cout << "3. delete record" << endl;
    cout << "4. edit record" << endl;
    cout << "5. display record" << endl;
    cout << "Enter your choice? ";
    cin >> choice;
    if (choice == 1)
      Transaction::createRecord();
    else if (choice == 2)
      Transaction::addRecord();
    else if (choice == 3)
      Transaction::deleteRecord();
    else if (choice == 4)
      Transaction::editRecord();
    else if (choice == 5)
      Transaction::displayRecord();
  } while(choice >0 && choice <=5);
}