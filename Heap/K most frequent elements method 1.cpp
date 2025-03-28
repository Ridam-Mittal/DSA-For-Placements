/*
Analysis:
- Time Complexity: O(N log N)
  1. Counting frequencies → O(N)
  2. Pushing elements into a Max Heap → O(N log N)
  3. Extracting K elements from the heap → O(K log N)
  => Overall: O(N log N)

- Space Complexity: O(N)
  1. Frequency map stores O(N) elements
  2. Max Heap stores O(N) elements in the worst case
  3. Result vector stores O(K) elements
  => Overall: O(N)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        unordered_map<int, int> u;

        for (int i = 0; i < nums.size(); i++) {
            u[nums[i]]++;
        }

        for (auto &i : u) {
            q.push({i.second, i.first});
        }

        vector<int> ans;
        while (k--) {
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution sol;
    vector<int> result = sol.topKFrequent(nums, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
