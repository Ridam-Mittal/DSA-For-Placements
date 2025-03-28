
#include <iostream>
#include <vector>
using namespace std;

// Function to find the lower bound of x
int lowerBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = mid;    // Record the potential answer
            high = mid - 1; // Look for a smaller index
        } else {
            low = mid + 1;  // Move to the right
        }
    }
    return ans;
}


// Function to find the upper bound of x
int upperBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            ans = mid;    // Record the potential answer
            high = mid - 1; // Look for a smaller index
        } else {
            low = mid + 1;  // Move to the right
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 5, 6, 8, 9};
    int n = arr.size();
    int x = 4;

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    if (lb != -1)
        cout << "Lower Bound of " << x << ": Index " << lb << ", Value " << arr[lb] << endl;
    else
        cout << "Lower Bound of " << x << ": Not found" << endl;

    if (ub != -1)
        cout << "Upper Bound of " << x << ": Index " << ub << ", Value " << arr[ub] << endl;
    else
        cout << "Upper Bound of " << x << ": Not found" << endl;

    return 0;
}