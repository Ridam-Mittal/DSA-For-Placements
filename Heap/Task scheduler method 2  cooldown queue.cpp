#include <bits/stdc++.h>
using namespace std;

/*
✅ Approach 2: Using a Queue to Track Cooldowns
------------------------------------------------
- Uses a queue to keep track of cooldown times explicitly.
- The task is scheduled at time, so it should be available after n+1 steps.
- This ensures the task waits exactly n full intervals before reappearing.

🔹 Time Complexity: O(N log N) (heap operations)
🔹 Space Complexity: O(N) (queue storage)
*/

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;
    
    // Step 1: Count task frequencies
    for (char task : tasks) freq[task]++;

    // Step 2: Max heap to schedule most frequent tasks first
    priority_queue<int> pq;
    for (auto& f : freq) pq.push(f.second);

    // Step 3: Queue to track cooldown tasks {remaining count, available time}
    queue<pair<int, int>> cooldown;
    int time = 0;

    while (!pq.empty() || !cooldown.empty()) {
        time++;

        // If a task's cooldown is over, push it back to the heap
        if (!cooldown.empty() && cooldown.front().second == time) {
            pq.push(cooldown.front().first);
            cooldown.pop();
        }

        // Schedule the most frequent available task
        if (!pq.empty()) {
            int count = pq.top() - 1;
            pq.pop();
            if (count > 0) {
                cooldown.push({count, time + n + 1});  // Cooldown period
            }
        }
    }

    return time;
}

// Driver Code
int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << "Minimum time using queue-based cooldown: " << leastInterval(tasks, n) << endl;  
    return 0;
}
