#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int low = 0;
		int high = nums.size() - 1;
		int mid = low + (high - low) / 2;
		int ans = INT_MAX;

		while (low <= high) {

			if(nums[low] <= nums[high]){
				ans = min(ans, nums[low]);
				break;
			}

			if (nums[low] <= nums[mid]) {  // Left part is sorted
				ans = min(ans, nums[low]);  // Update ans with the minimum value in the left
				low = mid + 1;  // Move to the right half
			} else {  // Right part is sorted
				ans = min(ans, nums[mid]);  // Update ans with the minimum value in the right
				high = mid - 1;  // Move to the left half
			}

			mid = low + (high - low) / 2;
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<int> nums = {3, 4, 5 , 7, 8, 0, 1, 2};  
	cout << "Minimum element is: " << sol.findMin(nums) << endl;
	return 0;
}
