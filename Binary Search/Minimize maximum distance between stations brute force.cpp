#include <bits/stdc++.h>
using namespace std;

double findSmallestMaxDist(vector<int> &stations, int k) {
    int n = stations.size();
    vector<int> howmany(n - 1, 0);

    for (int i = 1; i <= k; i++) {
        double maxvalue = -1;
        int maxindex = -1;

        for (int j = 0; j < n - 1; j++) {
            int diff = stations[j + 1] - stations[j];
            double sectionlength = (double) diff / (howmany[j] + 1);

            if (maxvalue < sectionlength) {
                maxvalue = sectionlength;
                maxindex = j;
            }
        }
        howmany[maxindex]++;
    }

    double ans = -1;
    for (int i = 0; i < n - 1; i++) {
        int diff = stations[i + 1] - stations[i];
        double sectionlength = (double) diff / (howmany[i] + 1);
        ans = max(ans, sectionlength);
    }

    return ans;
}

int main() {
    vector<int> stations = {1, 2, 5, 10}; // Example input
    int k = 2; // Number of additional stations

    double result = findSmallestMaxDist(stations, k);

    cout << fixed << setprecision(6) << "Minimum largest distance: " << result << endl;

    return 0;
}
