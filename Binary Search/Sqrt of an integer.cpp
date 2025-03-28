#include <iostream>
using namespace std;

int floorSqrt(int n) {
    int low = 1;
    int high = n;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid * mid == n) {
            return mid;
        } else if (mid * mid > n) {
            high = mid - 1;
        } else {
            low = mid + 1;
            ans = mid;
        }
    }

    return ans;
}

int main() {
    int n = 10; // Example input, modify as needed
    cout << "Floor square root of " << n << ": " << floorSqrt(n) << endl;
    return 0;
}
