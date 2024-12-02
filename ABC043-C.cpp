#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int min_cost = INT_MAX;
    for (int y = -100; y <= 100; y++) {
        int current_cost = 0;
        for (int i = 0; i < n; i++) {
            current_cost += (nums[i] - y) * (nums[i] - y);
        }
        min_cost = min(min_cost, current_cost);
    }
    cout << min_cost << '\n';
    return 0;
}
