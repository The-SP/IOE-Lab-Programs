#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int beg, int end) {
    int mid;
    while (beg <= end) {
        mid = (beg + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key > arr[mid])
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int key, int beg, int end) {
    if (beg <= end) {
        int mid = (beg + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key > arr[mid])
            return recursiveBinarySearch(arr, key, mid + 1, end);
        else
            return recursiveBinarySearch(arr, key, beg, mid - 1);
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 50, 60, 80, 100, 110, 130, 170};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Iterative binary search
    int key = 100;
    int result = binarySearch(arr, key, 0, n - 1);
    (result == -1)
        ? cout << "Element " << key << " not found"
        : cout << "Element " << key << " found at index " << result;
    cout << endl;
    // Recursive binary search
    key = 20;
    result = recursiveBinarySearch(arr, key, 0, n - 1);
    (result == -1)
        ? cout << "Element " << key << " not found"
        : cout << "Element " << key << " found at index " << result;
}