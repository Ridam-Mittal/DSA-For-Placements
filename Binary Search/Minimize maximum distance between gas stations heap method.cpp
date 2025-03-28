#include <bits/stdc++.h>
using namespace std;

long double findSmallestMaxDist(vector<int> &stations, int k) {
    int n = stations.size();
    vector<int> howmany(n - 1, 0);
    priority_queue<pair<long double, int>> q;

    // ✅ Correct difference calculation
    for (int i = 0; i < n - 1; i++) {
        long double diff = (long double)(stations[i + 1] - stations[i]); 
        q.push({diff, i});
    }

    for (int i = 1; i <= k; i++) {
        auto top = q.top();
        q.pop();

        int maxindex = top.second;
        howmany[maxindex]++;

        long double inidiff = (long double)(stations[maxindex + 1] - stations[maxindex]);
        long double sectionlength = inidiff / (howmany[maxindex] + 1);

        q.push({sectionlength, maxindex});
    }

    return q.top().first;
}

int main() {
    vector<int> stations = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = findSmallestMaxDist(stations, k);
    
    cout << fixed << setprecision(10) << "The answer is: " << ans << "\n";
    return 0;
}
