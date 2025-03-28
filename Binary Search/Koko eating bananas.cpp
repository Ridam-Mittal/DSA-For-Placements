#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long int findhrs(int mid, vector<int>& piles) {
    long long int hrs = 0;
    for (int i = 0; i < piles.size(); i++) {
        hrs += (piles[i] + mid - 1) / mid; // Efficient rounding up
    }
    return hrs;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int ans = INT_MAX;
    int low = 1;
    int high = piles[0];
    for (int i = 0; i < piles.size(); i++) {
        if (high < piles[i]) {
            high = piles[i];
        }
    }
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long int hrs = findhrs(mid, piles);
        if (hrs > h) {
            low = mid + 1;
        } else {
            ans = min(ans, mid);
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> piles = {3, 6, 7, 11}; // Example input: number of bananas in each pile
    int h = 8; // Example input: hours to eat all bananas
    cout << "Minimum eating speed: " << minEatingSpeed(piles, h) << endl;
    return 0;
}
