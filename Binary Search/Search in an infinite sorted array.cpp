#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
	while (low <= high) {

		int mid = (low + high) / 2;
		if (arr[mid] < key) {
			low = mid + 1;
		} else if (arr[mid] > key) {
			high = mid - 1;
		} else {
			return mid;
		}

	}
	return -1;
}

int findIndex(int arr[], int key) {
	int low = 0;
	int high = 1;
	while (arr[high] < key) {
		low = high;
		high = 2 * high;
	}
	return binarySearch(arr, low, high, key);
}

int main() {
	// Your code goes here;
	int arr[] = {3,5,7,9,10,90,100,130,140,160,170};

	int ans = findIndex(arr, 130);

	cout << "Element found at index " << ans;

	return 0;
}
/*
        Output:     Element found at index 7
        
        Time Complexity:    O(logN) + O(logN) = O(logN)
        Space Complexity:   O(1)
        
*/