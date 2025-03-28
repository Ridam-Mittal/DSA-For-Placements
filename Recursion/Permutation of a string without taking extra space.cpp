#include <bits/stdc++.h>
using namespace std;

void solve(string s, vector<string>& v, int ind) {
    if (ind == s.size()) {
        v.push_back(s);
        return;
    }
    
    unordered_set<char> seen;
    for (int i = ind; i < s.length(); i++) {
        if (seen.find(s[i]) != seen.end()) continue; // Skip duplicates
        seen.insert(s[i]);
        
        swap(s[i], s[ind]);
        solve(s, v, ind + 1);
        swap(s[i], s[ind]);  // Backtrack
    } 
}

vector<string> findPermutation(string &s) {
    vector<string> v;
    solve(s, v, 0);
    return v;
}

// **Driver Code**
int main() {
    string s = "aab";  // Example input
    vector<string> result = findPermutation(s);

    cout << "Unique Permutations:\n";
    for (const string &perm : result) {
        cout << perm << endl;
    }

    return 0;
}
