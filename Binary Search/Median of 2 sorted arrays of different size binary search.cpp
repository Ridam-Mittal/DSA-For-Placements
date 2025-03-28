#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();

    // Ensure nums1 is the smaller array for efficiency
    if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

    int low = 0, high = n1;
    int total = n1 + n2;
    int left = (total + 1) / 2;

    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
        int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
        int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
        int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            // If total elements are even, return average of two middle elements
            if (total % 2 == 0) {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } 
            // If total elements are odd, return max of left half
            else {
                return max(l1, l2);
            }
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }

    return 0.0;  // Should never reach here
}

int main() {
    vector<int> nums1 = {1, 3, 8};
    vector<int> nums2 = {7, 9, 10, 11};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "The median is: " << median << endl;

    return 0;
}
