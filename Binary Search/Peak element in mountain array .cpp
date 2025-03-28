#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return 0;
    if (nums[0] > nums[1]) return 0;
    if (nums[n-1] > nums[n-2]) return n-1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;

        // increasing side of mountain so it will be on right
        if (nums[mid] > nums[mid - 1]) {
            low = mid + 1;
        } 
        // decreasing side of mountain so it will be on left
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 2, 3, 1}; 
    cout << "Peak element index: " << findPeakElement(nums) << endl;
    return 0;
}
