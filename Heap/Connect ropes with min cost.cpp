#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minCost(vector<int>& arr) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int num : arr) {
        q.push(num);
    }

    int ans = 0;
    while (q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();

        int c = a + b;
        ans += c;
        q.push(c);
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 3, 2, 6};
    cout << minCost(arr) << endl;
    return 0;
}
