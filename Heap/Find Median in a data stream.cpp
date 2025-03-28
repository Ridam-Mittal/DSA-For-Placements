#include <bits/stdc++.h>
using namespace std;

/**
 * 📌 MedianFinder Class: Maintains a stream of numbers and retrieves the median efficiently.
 * 
 * 🔹 Data Structure Used:
 *    - `maxq` (Max Heap): Stores the smaller half of the numbers.
 *    - `minq` (Min Heap): Stores the larger half of the numbers.
 * 
 * 🔹 Key Properties:
 *    - `maxq.size() >= minq.size()` is always maintained.
 *    - `maxq.size() - minq.size() ≤ 1` ensures the correct median retrieval.
 * 
 * 📌 Time & Space Complexity Analysis:
 *    - `addNum(int num)`: **O(log N)** due to heap insertions and balancing.
 *    - `findMedian()`: **O(1)** since the median is retrieved from `top()` of heaps.
 *    - Space Complexity: **O(N)** (storing all elements in heaps).
 * 
 * 🔹 Condition Summary Table:
 * | Condition                         | Action Taken                    |
 * |------------------------------------|---------------------------------|
 * | `minq.size() > maxq.size()`        | Move `minq.top()` to `maxq`    |
 * | `maxq.size() - minq.size() > 1`    | Move `maxq.top()` to `minq`    |
 * | `maxq.size() == minq.size()`       | Median = Avg of both tops      |
 * | `maxq.size() > minq.size()`        | Median = `maxq.top()`          |
 */

class MedianFinder {
public:
    priority_queue<int> maxq;  // Max Heap (Stores smaller half)
    priority_queue<int, vector<int>, greater<int>> minq;  // Min Heap (Stores larger half)

    MedianFinder() {}

    void addNum(int num) {
        if (maxq.empty()) {
            maxq.push(num);
            return;
        }

        // Insert into the correct heap
        if (num > maxq.top()) {
            minq.push(num);
        } else {
            maxq.push(num);
        }

        // Balance the heaps if needed
        if (minq.size() > maxq.size()) {
            maxq.push(minq.top());
            minq.pop();
        } else if (maxq.size() - minq.size() > 1) {
            minq.push(maxq.top());
            maxq.pop();
        }
    }

    double findMedian() {
        if (maxq.size() == minq.size()) {
            return (maxq.top() + minq.top()) / 2.0;
        }
        return maxq.top();
    }
};

// Driver Code
int main() {
    MedianFinder mf;
    
    mf.addNum(1);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1

    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.5

    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2

    mf.addNum(4);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2.5

    mf.addNum(5);
    cout << "Median: " << mf.findMedian() << endl; // Output: 3

    return 0;
}
