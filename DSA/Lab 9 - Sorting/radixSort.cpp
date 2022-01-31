#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

void countSort(int arr[], int n, int pos) {
    int output[n]; 
    int i, count[10] = { 0 };

    // Store count of occurrences
    for (i=0; i<n; i++)
        count[(arr[i]/pos)%10]++;

    // Calculate comulative count (i.e. Change count[i] so that it contains actual position of digit in output[] )
    for (i=1; i<10; i++)
        count[i] += count[i-1];

    for (i=n-1; i>=0; i--)
        output[--count[(arr[i]/pos)%10]] = arr[i];

    // Copy output[] to arr[], so that arr[] now contains sorted numbers according to current digit
    for (i=0; i<n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    // find max to get no of passes
    int max = getMax(arr, n);
    // Apply count sort to sort elements based on place value
    for (int pos=1; max/pos > 0; pos*=10)
        countSort(arr, n, pos);
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main() {
    int arr[] = {141, 456, 342, 789, 90, 2, 870, 192, 938, 243};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Initial array: \t";
    displayArray(arr, n);
    radixSort(arr, n);
    cout << "Sorted array: \t";
    displayArray(arr, n);
    return 0;
}