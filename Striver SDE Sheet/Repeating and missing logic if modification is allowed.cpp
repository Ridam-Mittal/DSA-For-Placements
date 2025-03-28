#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//  If modification is allowed

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size();
    int repeating = 0;

    // Find the repeating number
    for (int i = 0; i < n; i++) {
        int idx = abs(a[i]) - 1;
        if (a[idx] < 0) {
            repeating = abs(a[i]);
            break;
        }
        a[idx] = -a[idx]; // Mark as visited
    }

    // Calculate the missing number
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(a[i]); // Use abs() to ensure correct sum
    }

    int idealSum = (n * (n + 1)) / 2;
    int missing = idealSum + repeating - sum;

    return {repeating, missing};
}

// Main function for testing
int main() {
    vector<int> nums = {8, 4, 1, 6, 7, 2, 5, 8};  // Example input
    vector<int> result = findMissingRepeatingNumbers(nums);
    
    cout << "Repeating: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;
}
