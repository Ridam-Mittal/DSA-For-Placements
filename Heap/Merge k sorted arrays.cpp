/*
Merge K Sorted Arrays - Comparison of Approaches:

1️⃣ Merge Sort (Divide & Conquer):
   - Time Complexity: O(N log K)
   - Space Complexity: O(N) (for storing merged output)
   - Uses recursive merging in a pairwise manner.

2️⃣ Min Heap (Priority Queue) [This Code]:
   - Time Complexity: O(N log K)
   - Space Complexity: O(K) (heap storage)
   - Iteratively picks the smallest element from K arrays using a Min Heap.
   - More space-efficient than Merge Sort when K is small.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    
    for (int i = 0; i < K; i++) {
        q.push({ arr[i][0], { i, 0 }});
    }

    vector<int> ans;
    while (!q.empty()) {
        int top = q.top().first;
        int apos = q.top().second.first;
        int pos = q.top().second.second;
        q.pop();
        ans.push_back(top);
        pos++;
        if (pos < arr[apos].size()) {
            q.push({ arr[apos][pos], { apos, pos}});
        }
    }
    
    return ans;
}

int main() {
    vector<vector<int>> arr = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    
    vector<int> result = mergeKArrays(arr, arr.size());
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
