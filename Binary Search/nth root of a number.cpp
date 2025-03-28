#include <iostream>
using namespace std;

int power(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }

    if (ans == m) return 1;
    return 0;
}

int nthRoot(int n, int m) {
    int low = 1;
    int high = m;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int powmid = power(mid, n, m);
        if (powmid == 1) {
            return mid;
        } else if (powmid == 2) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n = 3; // Example: nth root (e.g., cube root)
    int m = 27; // Example: Find the cube root of 27
    cout << "The " << n << "th root of " << m << " is: " << nthRoot(n, m) << endl;
    return 0;
}
