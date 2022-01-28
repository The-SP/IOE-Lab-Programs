#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* Take first element as pivot
 place the pivot element at its correct position in sorted array, 
 place all smaller elements to left of pivot and
 place all greater elements to right of pivot */
int partition(int arr[], int lb, int ub) {
    int start = lb, end = ub; // lb = lower bound, ub = upper bound
    int pivot = arr[lb];
    while (start < end) {
        while (arr[start] <= pivot && start < ub)
            start++;
        while (arr[end] > pivot && end > lb)
            end--;
        if (start < end)
            swap(&arr[start], &arr[end]);
    }
    swap(&arr[lb], &arr[end]); // swap pivot to its correct index and return its index
    return end;
}

void quickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        /* pi is partitioning index, arr[pi] is at its correct index */
        int pi = partition(arr, lb, ub);
        // Separately sort elements before partition and after partition
        quickSort(arr, lb, pi - 1);
        quickSort(arr, pi + 1, ub);
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main() {
    int arr[] = {10, 80, 30, 25, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Initial array: \t";
    displayArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \t";
    displayArray(arr, n);
    return 0;
}