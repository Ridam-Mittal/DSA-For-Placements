#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> replaceWithMinRank(vector<int> &arr, int N) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < N; i++) {
        q.push({arr[i], i});
    }

    int rank = 1;
    pair<int, int> prev = {-1, -1};

    while (!q.empty()) {
        int index = q.top().second;
        int value = q.top().first;
        q.pop();

        if (prev.first == -1 || value != prev.first) {
            prev = {value, rank};
            arr[index] = rank;
            rank++;
        } else {
            arr[index] = prev.second;
        }
    }

    return arr;
}

int main() {
    vector<int> arr = {40, 10, 30, 20};
    vector<int> result = replaceWithMinRank(arr, arr.size());

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
