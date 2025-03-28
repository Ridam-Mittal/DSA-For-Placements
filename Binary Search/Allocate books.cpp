#include <bits/stdc++.h>
using namespace std;

int distribute(vector<int>& arr, int k, int mid) {
    int student = 1;
    int pages = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        if (pages + arr[i] <= mid) {
            pages += arr[i];
        } else {
            pages = arr[i];
            student++;
            if (student > k) {
                return 0;
            }
        }
    }
    return 1;
}

int findPages(vector<int>& arr, int k) {
    if (k > arr.size()) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (distribute(arr, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {12, 34, 67, 90}; // Example book pages
    int k = 2; // Number of students

    int result = findPages(arr, k);
    
    if (result == -1)
        cout << "Not possible to distribute books." << endl;
    else
        cout << "Minimum maximum pages a student can get: " << result << endl;

    return 0;
}
