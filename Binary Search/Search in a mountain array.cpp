#include <bits/stdc++.h>
using namespace std;

class MountainArray {
private:
    vector<int> arr;
public:
    MountainArray(vector<int> input) : arr(input) {}

    int get(int index) {
        return arr[index];
    }

    int length() {
        return arr.size();
    }
};

int findInMountainArray(int target, MountainArray &mountainArr) {
    int length = mountainArr.length();
    int peak = -1;

    int low = 1, high = length - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mountainArr.get(mid) > mountainArr.get(mid - 1) && mountainArr.get(mid) > mountainArr.get(mid + 1)) {
            peak = mid;
            break;
        }
        else if (mountainArr.get(mid) > mountainArr.get(mid - 1)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    low = 0, high = peak;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midVal = mountainArr.get(mid);
        if (midVal == target) return mid;
        else if (midVal > target) high = mid - 1;
        else low = mid + 1;
    }

    low = peak + 1, high = length - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midVal = mountainArr.get(mid);
        if (midVal == target) return mid;
        else if (midVal > target) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 2, 4, 5, 3, 1};  // Example Mountain Array
    MountainArray mountainArr(arr);

    int target = 3;
    int result = findInMountainArray(target, mountainArr);

    if (result != -1)
        cout << "Target " << target << " found at index: " << result << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}
