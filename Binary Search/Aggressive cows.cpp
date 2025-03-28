#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ispossible(vector<int>& stalls, int mid, int k) {
    int cows = 1;
    int prev = 0;
    for(int i = 1; i < stalls.size(); i++) {
        if(stalls[i] - stalls[prev] >= mid) {
            cows++;
            prev = i;
        }
        if(cows == k) {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    if(k == 1) return 0;
    int low = 1;
    int high = stalls[stalls.size()-1] - stalls[0];
    int ans = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        bool check = ispossible(stalls, mid, k);
        if(check == true) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};  // Example input
    int k = 3;  // Number of cows
    cout << "Maximum minimum distance: " << aggressiveCows(stalls, k) << endl;
    return 0;
}
