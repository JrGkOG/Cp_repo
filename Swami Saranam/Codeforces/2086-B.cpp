#include <bits/stdc++.h>
using namespace std;

#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);

#define int long long


void CoderAbhi27() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int s = accumulate(a.begin(), a.end(), 0LL); // n

    if (x > k * s) {
        cout << "0\n";
        return;
    }

    int xm = x % s;
    int q = x / s;
    if (xm == 0) {
        q--;
        xm = s;
    }

    int ans = n * k - q * n;
    int suf = 0;
    for (int i = n - 1; i >= 0; i--) {
        suf += a[i];
        if (suf >= xm)
            break;
        ans--;
    } // n

    cout << ans << '\n';
}

// tc : O(n)
// sc : O(n)

int32_t main() {
    fastIO;

    int t = 1;
    cin >> t;
    while (t--) {
        CoderAbhi27();
    }
    return 0;
}