#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
    Intuition:
    - We use a **Min Heap** (priority queue) of size `k` to efficiently track the k largest elements.
    - The **top of the heap** will always store the **Kth largest element**.
    - **Algorithm:**
        1. Insert the first `k` elements into the heap.
        2. For each remaining element:
           - If it's larger than the heap's top, remove the smallest and insert the new element.
        3. At the end, the heap's top contains the Kth largest element.
    - **Time Complexity:** O(N log K) (better than O(N log N) sorting)
    - **Space Complexity:** O(K) (heap stores only `k` elements)
*/

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;  

    for (int num : nums) {
        if (minHeap.size() < k) {
            minHeap.push(num);  
        } 
        else if (num > minHeap.top()) {  
            minHeap.pop();      
            minHeap.push(num);  
        }
    }
    return minHeap.top();  
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;  

    cout << "The " << k << "th largest element is: " << findKthLargest(nums, k) << endl;
    return 0;
}
