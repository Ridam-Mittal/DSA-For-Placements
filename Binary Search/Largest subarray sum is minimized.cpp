#include <bits/stdc++.h>
using namespace std;

bool ispossible(vector<int>& nums, int k, int mid) {
    int partitions = 1;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (sum + nums[i] > mid) {
            partitions++;
            sum = nums[i];
            if (partitions > k) {
                return false;
            }
        } else {
            sum += nums[i];
        }
    }
    return true;
}

int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ispossible(nums, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8}; // Example input
    int k = 2; // Number of partitions

    int result = splitArray(nums, k);
    
    cout << "Minimum largest sum among " << k << " subarrays: " << result << endl;
    
    return 0;
}
