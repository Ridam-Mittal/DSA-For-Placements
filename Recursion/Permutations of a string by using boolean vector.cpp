#include <bits/stdc++.h>
using namespace std;

void solve(string &s, string t, set<string>& st, vector<bool>& x) {
    if (t.size() == s.size()) {
        st.insert(t); // Insert into set to remove duplicates
        return;
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (!x[i]) {
            x[i] = true;
            t += s[i];
            solve(s, t, st, x);
            t.pop_back();  // Backtrack
            x[i] = false;
        }
    }
}

vector<string> findPermutation(string &s) {
    set<string> st;
    string t;
    vector<bool> x(s.length(), false);
    solve(s, t, st, x);
    return vector<string>(st.begin(), st.end()); // Convert set to vector
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
