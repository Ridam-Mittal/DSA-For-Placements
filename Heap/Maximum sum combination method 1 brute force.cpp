#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*  the brute-force approach using a priority queue takes O(n1 * n2 log C) time complexity,
*/

vector<int> solve(vector<int>& A, vector<int>& B, int C) {
    priority_queue<int, vector<int>, greater<int>> q;
    
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            q.push(A[i] + B[j]);
            if (q.size() > C) {
                q.pop();
            }
        }
    }

    vector<int> result(C);
    for (int i = C - 1; i >= 0; i--) {
        result[i] = q.top();
        q.pop();
    }

    return result;
}

/* Example Usage */
int main() {
    vector<int> A = {1, 2, 3};
    vector<int> B = {4, 5, 6};
    int C = 3;

    vector<int> result = solve(A, B, C);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
