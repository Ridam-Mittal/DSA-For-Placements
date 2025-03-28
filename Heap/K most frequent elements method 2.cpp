/*
Optimized Approach using Min Heap:
- Time Complexity: O(N log K)
  1. Counting frequencies → O(N)
  2. Pushing elements into a Min Heap of size K → O(N log K)
  3. Extracting K elements from the heap → O(K log K)
  => Overall: O(N log K)

- Space Complexity: O(N)
  1. Frequency map stores O(N) elements
  2. Min Heap stores at most O(K) elements
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
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto &p : freq) {
            minHeap.push({p.second, p.first});
            if (minHeap.size() > k) {
                minHeap.pop();  // Keep only top K elements
            }
        }

        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
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
