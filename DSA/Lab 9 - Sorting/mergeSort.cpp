#include <iostream>
using namespace std;

void merge(int arr[], int lb, int mid, int ub) {
    int i = lb, k = lb, j = mid + 1;
    int b[lb + ub + 1];
    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j])
            b[k] = arr[i++];
        else
            b[k] = arr[j++];
        k++;
    }
    while (i <= mid)
        b[k++] = arr[i++];
    while (j <= ub)
        b[k++] = arr[j++];
    for (int k = lb; k <= ub; k++)
        arr[k] = b[k];
}

void mergeSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main() {
    int arr[] = {10, 80, 30, 25, 90, 40, 50, 70, 12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Initial array: \t";
    displayArray(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: \t";
    displayArray(arr, n);
    return 0;
}