#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> x(n), r(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> r[i];
    
    // Find the range of x coordinates we need to consider
    int minX = LLONG_MAX, maxX = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        minX = min(minX, x[i] - r[i]);
        maxX = max(maxX, x[i] + r[i]);
    }
    
    int totalPoints = 0;
    
    // For each x-coordinate in the range
    for (int currX = minX; currX <= maxX; currX++) {
        // Find vertical range (min and max y) across all circles for this x
        vector<pair<int, int>> ranges; // (start_y, end_y) inclusive ranges
        
        for (int i = 0; i < n; i++) {
            int xi = x[i], ri = r[i];
            int dx = currX - xi;
            
            // Check if this x is within the circle's x-range
            if (abs(dx) > ri) continue;
            
            // Calculate max y value at this x-coordinate
            int yMaxSquared = ri * ri - dx * dx;
            int yMax = sqrt(yMaxSquared);
            ranges.push_back({-yMax, yMax});
        }
        if (ranges.empty()) continue;
        sort(ranges.begin(), ranges.end());
        vector<pair<int, int>> mergedRanges;
        mergedRanges.push_back(ranges[0]);
        for (int i = 1; i < ranges.size(); i++) {
            pair<int, int> &last = mergedRanges.back();
            pair<int, int> &curr = ranges[i];
            if (curr.first <= last.second + 1) {
                last.second = max(last.second, curr.second);
            } else {
                mergedRanges.push_back(curr);
            }
        }
        for (auto &range : mergedRanges) {
            totalPoints += range.second - range.first + 1;
        }
    }
    cout << totalPoints << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}