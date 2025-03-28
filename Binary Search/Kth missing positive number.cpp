#include <iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return k + low;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    
    int result = findKthPositive(arr, k);
    cout << "The " << k << "th missing positive number is: " << result << endl;
    
    return 0;
}
