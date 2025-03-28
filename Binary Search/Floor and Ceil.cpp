#include <iostream>
#include <vector>
using namespace std;

int findFloor(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int floors = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x) {
            return mid;  // Exact match, floor is the element itself
        }
        else if (arr[mid] < x) {
            floors = arr[mid];  // Potential floor, store it
            low = mid + 1;     // Look in the right half for a larger floor
        }
        else {
            high = mid - 1;    // Look in the left half
        }
    }
    
    return floors;  // Return floor (if any)
}

int findCeil(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ceils = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x) {
            return mid;  // Exact match, ceil is the element itself
        }
        else if (arr[mid] > x) {
            ceils = arr[mid];  // Potential ceil, store it
            high = mid - 1;   // Look in the left half for a smaller ceil
        }
        else {
            low = mid + 1;    // Look in the right half
        }
    }
    
    return ceils;  // Return ceil (if any)
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 15};
    int x = 6;
    
    int floors = findFloor(arr, x);
    int ceils = findCeil(arr, x);
    
    cout << "Floor of " << x << ": " << floors << endl;
    cout << "Ceil of " << x << ": " << ceils << endl;
    
    return 0;
}
