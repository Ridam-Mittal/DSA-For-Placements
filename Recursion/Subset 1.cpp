#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int i, int n, vector<int>& ans, int sum, vector<int>& subset, vector<vector<int>>& subsets) {
    if (i == n) {
        ans.push_back(sum);
        subsets.push_back(subset);
        return;
    }

    // Not take
    solve(arr, i + 1, n, ans, sum, subset, subsets);

    // Take
    subset.push_back(arr[i]);
    solve(arr, i + 1, n, ans, sum + arr[i], subset, subsets);
    subset.pop_back();  // Backtrack
}

void subsetSums(vector<int>& arr) {
    vector<int> ans;
    vector<vector<int>> subsets;
    vector<int> subset;

    solve(arr, 0, arr.size(), ans, 0, subset, subsets);

    // Printing all subsets
    cout << "Subsets and Their Sums:\n";
    for (size_t i = 0; i < subsets.size(); i++) {
        cout << "{ ";
        for (int num : subsets[i]) {
            cout << num << " ";
        }
        cout << "} -> Sum = " << ans[i] << endl;
    }
}

// **Driver Code**
int main() {
    vector<int> arr = {1, 2, 1};  // Example Input
    subsetSums(arr);
    return 0;
}
