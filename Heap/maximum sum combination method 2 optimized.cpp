#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

/*
🔹 Step 1: Sort both arrays in descending order to ensure the largest sums come first.
🔹 Step 2: Use a max heap (priority queue) to efficiently track the largest sums.
🔹 Step 3: Push only the best possible sums and dynamically expand from the top.
🔹 Step 4: Maintain a set to avoid duplicate pairs.

Time Complexity: O(n log n + C log C)
Space Complexity: O(C) (for heap + result storage)

📊 Dry Run Example:
Input:
A = {10, 8, 6, 4}   // Sorted: {10, 8, 6, 4}
B = {9, 7, 5, 3}    // Sorted: {9, 7, 5, 3}
C = 6

Processing Heap:
| Step | Extracted Sum | Pushed (i+1, j) | Pushed (i, j+1) | Heap After Push |
|------|--------------|----------------|----------------|-----------------|
| 1 | (10+9) = 19, {0,0} | (8+9) = 17, {1,0} | (10+7) = 17, {0,1} | {(17, {1,0}), (17, {0,1})} |
| 2 | (8+9) = 17, {1,0} | (6+9) = 15, {2,0} | (8+7) = 15, {1,1} | {(17, {0,1}), (15, {2,0}), (15, {1,1})} |
| 3 | (10+7) = 17, {0,1} | (10+5) = 15, {0,2} | N/A | {(15, {2,0}), (15, {1,1}), (15, {0,2})} |
| 4 | (6+9) = 15, {2,0} | (4+9) = 13, {3,0} | (6+7) = 13, {2,1} | {(15, {1,1}), (15, {0,2}), (13, {3,0}), (13, {2,1})} |
| 5 | (8+7) = 15, {1,1} | (8+5) = 13, {1,2} | N/A | {(15, {0,2}), (13, {3,0}), (13, {2,1}), (13, {1,2})} |
| 6 | (10+5) = 15, {0,2} | (10+3) = 13, {0,3} | N/A | {(13, {3,0}), (13, {2,1}), (13, {1,2}), (13, {0,3})} |

Final Output:
{19, 17, 17, 15, 15, 15}
*/

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    priority_queue<pair<int, pair<int, int>>> maxHeap;
    set<pair<int, int>> seen;

    maxHeap.push({A[0] + B[0], {0, 0}});
    seen.insert({0, 0});

    vector<int> result;

    while (C-- && !maxHeap.empty()) {
        auto top = maxHeap.top();
        maxHeap.pop();

        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;

        result.push_back(sum);

        if (i + 1 < A.size() && seen.find({i + 1, j}) == seen.end()) {
            maxHeap.push({A[i + 1] + B[j], {i + 1, j}});
            seen.insert({i + 1, j});
        }

        if (j + 1 < B.size() && seen.find({i, j + 1}) == seen.end()) {
            maxHeap.push({A[i] + B[j + 1], {i, j + 1}});
            seen.insert({i, j + 1});
        }
    }

    return result;
}

int main() {
    vector<int> A = {10, 8, 6, 4};
    vector<int> B = {9, 7, 5, 3};
    int C = 6;

    vector<int> result = solve(A, B, C);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
