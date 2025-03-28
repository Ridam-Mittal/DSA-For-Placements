#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = low + (high - low) / 2;

    while (low <= high) {
        if (nums[mid] == target) {
            return true;
        }
        // Handle duplicates
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }
        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target <= nums[mid]) {
                high = mid - 1; // Target is in the left half
            } else {
                low = mid + 1; // Target is in the right half
            }
        } 
        // Right half is sorted
        else {
            if (nums[mid] <= target && target <= nums[high]) {
                low = mid + 1; // Target is in the right half
            } else {
                high = mid - 1; // Target is in the left half
            }
        }
        mid = low + (high - low) / 2;
    }
    return false;
}

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    if (search(nums, target)) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
