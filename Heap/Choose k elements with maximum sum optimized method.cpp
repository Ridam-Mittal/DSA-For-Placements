#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    vector<long long> ans(n, 0);
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        v.push_back({nums1[i], i});
    }

    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> q;
    long long sum = 0;
    ans[v[0].second] = sum;

    for (int i = 1; i < n; i++) {
        sum += nums2[v[i - 1].second];
        q.push(nums2[v[i - 1].second]);

        if (q.size() > k) {
            sum -= q.top();
            q.pop();
        }

        if (v[i].first == v[i - 1].first) {
            ans[v[i].second] = ans[v[i - 1].second];
        } else {
            ans[v[i].second] = sum;
        }
    }

    return ans;
}

int main() {
    vector<int> nums1 = {4, 2, 7, 1, 5};
    vector<int> nums2 = {10, 5, 8, 3, 6};
    int k = 2;

    vector<long long> result = findMaxSum(nums1, nums2, k);

    for (long long num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
