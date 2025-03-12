#include <bits/stdc++.h>
using namespace std;

bool canReduceToX(int n, int x, const vector<int>& a) {
    int sum_a = 0;
    for (int num : a) {
        sum_a += num;
    }
    return sum_a == x * n;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << (canReduceToX(n, x, a) ? "YES" : "NO") << endl;
    }
    return 0;
}