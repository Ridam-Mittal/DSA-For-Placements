#include <iostream>
#include <vector>
using namespace std;


int firstocc(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == x){
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid] > x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int lastocc(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == x){
            ans = mid;
            low = mid+1;
        }
        else if(arr[mid] > x){
            high = mid-1;
        }
        else{
           low = mid+1; 
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 5, 6, 8, 9};
    int n = arr.size();
    int x = 1;
    
    int fo = firstocc(arr, n, x);
    if(fo == -1){
        cout << -1 << " " << -1 << endl;
    }
    else{
        int lo = lastocc(arr, n, x);
        cout << fo << " " << lo << endl;
    }
}


