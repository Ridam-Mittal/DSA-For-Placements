#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    vector<long long> ans(n, 0);

    for (int i = 0; i < n; i++) {
        priority_queue<int> q;
        for (int j = 0; j < n; j++) {
            if (nums1[j] < nums1[i]) {
                q.push(nums2[j]);
            }
        }
        long long sum = 0;
        int c = k;
        while (!q.empty() && c--) {
            sum += q.top();
            q.pop();
        }
        ans[i] = sum;
    }
    return ans;
}

int main() {
    vector<int> nums1 = {4, 2, 7, 1};
    vector<int> nums2 = {10, 5, 8, 3};
    int k = 2;

    vector<long long> result = findMaxSum(nums1, nums2, k);

    for (long long num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
