
#include <iostream>
#include <vector>
using namespace std;

// Function to find the lower bound of x
int lowerBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1, ans = n;
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
    int low = 0, high = n - 1, ans = n;
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
    vector<int> arr = {1};
    int n = arr.size();
    int x = 1;
    
    int lb = lowerBound(arr, n, x);
    if(lb == n || arr[lb] != x) cout << -1 << " " << -1 << endl;
    else{
        int ub = upperBound(arr, n, x)-1;
        cout << lb << " " << ub << endl;
    }
}