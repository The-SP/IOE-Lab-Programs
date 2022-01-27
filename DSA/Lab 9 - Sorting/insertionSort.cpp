#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        /* Move elements of arr[i-1.....0], that are
        greater than key, to one position ahead
        of their current position */
        for (j = i - 1; (j >= 0 && arr[j] > key); j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key; // insert key to its proper place
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Initial array: \t";
    displayArray(arr, n);
    insertionSort(arr, n);
    cout << "Sorted array: \t";
    displayArray(arr, n);
    return 0;
}