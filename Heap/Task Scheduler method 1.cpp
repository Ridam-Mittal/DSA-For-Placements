#include <bits/stdc++.h>
using namespace std;

/*
✅ Approach 1: `n+1` Grouping (Using a Max Heap)
------------------------------------------------
- Greedy strategy: Always pick `n+1` most frequent tasks per cycle.
- Ensures different tasks fill the cooldown period.
- Efficient in minimizing idle time.
- This approach does NOT explicitly track cooldown but implicitly enforces it.

🔹 Time Complexity: O(N log N) (heap operations)
🔹 Space Complexity: O(N) (heap storage)
*/



/*

- The task that appeared the first time must have the highest freq count so even after the n+1 cycle ends the second most freq would also be able to maintain a gap of n b/w them as it will be the first most freq element again that comes after first cycle
*/
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;
    
    // Step 1: Count the frequency of each task
    for (char task : tasks) freq[task]++;

    // Step 2: Use a max heap to always schedule the most frequent task first
    priority_queue<int> pq;
    for (auto& f : freq) pq.push(f.second);

    int ans = 0;

    // Step 3: Process tasks in `n+1` groups
    while (!pq.empty()) {
        vector<int> v;  
        
        // Try to schedule `n+1` most frequent tasks in one cycle
        for (int i = 1; i <= n + 1; i++) {
            if (!pq.empty()) {
                int count = pq.top();
                pq.pop();
                count--;
                v.push_back(count);
            }
        }

        // Push remaining tasks back to heap
        for (int count : v) {
            if (count > 0) pq.push(count);
        }

        // If no tasks left, only count the executed tasks, otherwise count full cycle
        ans += pq.empty() ? v.size() : n + 1;
    }

    return ans;
}

// Driver Code
int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << "Minimum time using `n+1` approach: " << leastInterval(tasks, n) << endl;  
    return 0;
}
