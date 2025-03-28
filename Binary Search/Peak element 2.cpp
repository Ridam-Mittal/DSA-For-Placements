#include <bits/stdc++.h>
using namespace std;

int findMaxRow(vector<vector<int>>& mat, int mid, int m, int &rowi) {
	int maxi = mat[0][mid];
	rowi = 0;  // Ensure rowi starts at a valid index

	// Find the row index with the maximum element in column `mid`
	for (int i = 1; i < m; i++) {
		if (mat[i][mid] > maxi) {
			maxi = mat[i][mid];
			rowi = i;
		}
	}

	return maxi;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
	int m = mat.size();
	int n = mat[0].size();
	int low = 0, high = n - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		int rowi = 0;
		int maxi = findMaxRow(mat, mid, m, rowi);

		// Check left and right neighbors (if within bounds)
		int left = (mid > 0) ? mat[rowi][mid - 1] : -1;
		int right = (mid < n - 1) ? mat[rowi][mid + 1] : -1;

		// If the current element is greater than both left and right, it's a peak
		if (maxi > left && maxi > right) {
			return {rowi, mid};
		} else if (left > maxi) {  // Move left
			high = mid - 1;
		} else {  // Move right
			low = mid + 1;
		}
	}
	return {-1, -1}; // Should never be reached if there's at least one peak
}

// Driver code to test
int main() {
	vector<vector<int>> mat = {
		{1, 4, 3},
		{6, 8, 5},
		{7, 9, 6}
	};

	vector<int> peak = findPeakGrid(mat);
	cout << "Peak found at: [" << peak[0] << ", " << peak[1] << "]\n";

	return 0;
}
