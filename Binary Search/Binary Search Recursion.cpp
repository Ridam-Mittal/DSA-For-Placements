#include <iostream>
#include <vector>

using namespace std;

int bs(vector<int>& nums, int low, int high, int target) {
	if (low > high) {
		return -1;
	}
	int mid = low + (high - low) / 2;

	if (nums[mid] == target) {
		return mid;
	} else if (nums[mid] > target) {
		return bs(nums, low, mid - 1, target);
	} else {
		return bs(nums, mid + 1, high, target);
	}
}

int search(vector<int>& nums, int target) {
	return bs(nums, 0, nums.size() - 1, target);
}

int main() {
	vector<int> nums = {1, 3, 5, 7, 9};
	int target = 5;

	int result = search(nums, target);

	if (result != -1) {
		cout << "Target found at index: " << result << endl;
	} else {
		cout << "Target not found." << endl;
	}

	return 0;
}
