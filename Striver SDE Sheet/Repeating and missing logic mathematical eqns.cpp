#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size();
    long long idealsum = (1LL * n * (n + 1)) / 2;
    long long idealsos = (1LL * n * (n + 1) * (2 * n + 1)) / 6;
    long long sum = 0, sos = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        sos += (1LL * a[i] * a[i]);  // Ensure no overflow
    }

    // x - y
    long long xdiffy = sum - idealsum;
    // x + y
    long long xaddy = (sos - idealsos) / xdiffy;

    int x = (xaddy + xdiffy) / 2;
    int y = xaddy - x;

    return {x, y};
}

int main() {
    vector<int> arr = {4, 3, 6, 2, 1, 1}; // 1 is repeating, 5 is missing
    vector<int> ans = findMissingRepeatingNumbers(arr);
    cout << "Repeating: " << ans[0] << ", Missing: " << ans[1] << endl;
    return 0;
}
