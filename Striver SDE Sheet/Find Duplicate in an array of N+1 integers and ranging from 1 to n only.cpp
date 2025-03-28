#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Method 1: Brute Force (O(N^2) Time, O(1) Space)
int findDuplicateBruteForce(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] == nums[j]) {
                return nums[i];
            }
        }
    }
    return -1;
}

// Method 2: Modify Array (O(N) Time, O(1) Space)
int findDuplicateMarking(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        int idx = abs(nums[i]) - 1;  // Convert to index
        if (nums[idx] < 0) {
            return abs(nums[i]); // If already negative, duplicate found
        }
        nums[idx] = -nums[idx];  // Mark visited by negating the value
    }
    return -1;
}

// Method 3: Floyd's Cycle Detection Algorithm (O(N) Time, O(1) Space)
int findDuplicateFloyd(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // Step 1: Detect the cycle
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Step 2: Find the duplicate number
    fast = nums[0];  // Reset fast pointer to start
    while (fast != slow) {
        fast = nums[fast];
        slow = nums[slow];  // Corrected typo: "numsp" → "nums"
    }
    return slow;
}




/*
Slow and Fast Pointers Must Start at the Same Position; Unlike linked lists where any starting position works, in arrays, both slow and fast must start from nums[0].
This ensures that they traverse the cycle correctly. If we started fast at a different index, it could break the cycle detection logic.

*/

int main() {
    vector<int> nums = {3, 1, 3, 4, 2};

    cout << "Brute Force: " << findDuplicateBruteForce(nums) << endl;

    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << "Marking Method: " << findDuplicateMarking(nums2) << endl;

    vector<int> nums3 = {3, 1, 3, 4, 2};
    cout << "Floyd's Algorithm: " << findDuplicateFloyd(nums3) << endl;

    return 0;
}
