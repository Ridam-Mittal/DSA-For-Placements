#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int s = -1, e = -1; 
        int maxi = INT_MIN;
        int range = INT_MAX;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        
        for(int i = 0; i < nums.size(); i++) {
            q.push({ nums[i][0], { i, 0 }});
            maxi = max(maxi, nums[i][0]);
        }

        while (!q.empty()) {
            int mini = q.top().first;
            int ai = q.top().second.first;
            int index = q.top().second.second;
            q.pop();

            if (maxi - mini < range) {
                range = (maxi - mini);
                s = mini;
                e = maxi;
            }

            index++;
            if (index < nums[ai].size()) {
                q.push({ nums[ai][index], { ai, index }});
                maxi = max(maxi, nums[ai][index]);
            } else {
                break;
            }
        }
        return {s, e};
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<vector<int>> nums = { {4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30} };
    
    vector<int> result = sol.smallestRange(nums);
    cout << "Smallest Range: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
