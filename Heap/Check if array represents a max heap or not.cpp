#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {  // Start from the last non-leaf node
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] < arr[left]) {
            return false;  // Max Heap violated
        }
        if (right < n && arr[i] < arr[right]) {
            return false;  // Max Heap violated
        }
    }
    return true;
}

int main() {
    int arr[] = {90, 15, 10, 7, 12, 2, 5};  // Example of a Max Heap
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isMaxHeap(arr, n))
        cout << "The array represents a Max Heap\n";
    else
        cout << "The array does not represent a Max Heap\n";

    return 0;
}
