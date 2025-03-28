#include <bits/stdc++.h>
using namespace std;

int distribute(vector<int>& arr, int k, int mid) {
    int area = 0;
    int painter = 1;
    
    for (int i = 0; i < arr.size(); i++) {
        if (area + arr[i] <= mid) {
            area += arr[i];
        } else {
            area = arr[i];
            painter++;
            if (painter > k) {
                return 0;
            }
        }
    }
    return 1;
}

int minTime(vector<int>& arr, int k) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    int ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (distribute(arr, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {10, 20, 30, 40}; // Example board lengths
    int k = 2; // Number of painters

    int result = minTime(arr, k);

    cout << "Minimum time required: " << result << endl;
    
    return 0;
}
