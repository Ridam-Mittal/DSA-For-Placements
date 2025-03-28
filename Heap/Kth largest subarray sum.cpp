#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
✅ Time Complexity: O(N² log K)
✅ Space Complexity: O(K) (for the heap)
*/

int kthLargest(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if (q.size() == k && sum > q.top()) {
                q.pop();
                q.push(sum);
            } else if (q.size() < k) {
                q.push(sum);
            }
        }
    }
    return q.top();
}

int main() {
    vector<int> arr = {10, -10, 20, -40};
    int k = 3;
    cout << "Kth largest sum of subarray: " << kthLargest(arr, k) << endl;
    return 0;
}
