#include <iostream>
#include <vector>
using namespace std;

/*

✅ Your approach is the optimal method for:

- Converting a Min Heap to a Max Heap.
- Constructing a Max Heap from any arbitrary array.


*/


void heapify(vector<int>& arr, int N, int i) {
    int largest = i; 
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < N && arr[left] > arr[largest]) {
        largest = left;
    }
    

    if (right < N && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void convertMinToMaxHeap(vector<int>& arr, int N) {
    for (int i = (N / 2) - 1; i >= 0; i--) {
        heapify(arr, N, i);
    }
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 2, 6}; 
    int N = arr.size();

    cout << "Original Array (Min Heap): ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    convertMinToMaxHeap(arr, N);

    cout << "Converted Max Heap: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
