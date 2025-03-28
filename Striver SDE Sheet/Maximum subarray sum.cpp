#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
	int n = nums.size();
	int maxi = INT_MIN;
	int sum = 0;
	int s = 0, e = 0, start = 0;

	for (int i = 0; i < n; i++) {
		sum += nums[i];

		if (sum > maxi) {
			maxi = sum;
			s = start; // Update start of subarray
			e = i;
		}

		if (sum < 0) {
			sum = 0;
			start = i + 1; // Move start to the next element
		}
	}

	// Print the subarray contributing to max sum
	for (int i = s; i <= e; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;

	return maxi;
}


int maxSubArray(vector<int>& nums) {
	int maxi = INT_MIN;
	int n = nums.size();
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += nums[j];
			maxi = max(maxi, sum);
		}
	}

	return maxi;
}

int maxSubarraySum(int arr[], int n) {
	int maxi = INT_MIN; // maximum sum

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += arr[k];
			}
			maxi = max(maxi, sum);
		}
	}

	return maxi;
}


int main()
{
	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int maxSum = maxSubarraySum(arr, n);
	cout << "The maximum subarray sum is: " << maxSum << endl;
	return 0;
}

