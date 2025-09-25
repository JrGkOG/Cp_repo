#include <bits/stdc++.h>
#define int long long
#define p 1000000007
using namespace std;


void solve() {
    int l, r;
    cin >> l >> r;
    vector<int> ans(r+1,0);
    int temp = r;
    while (temp > 0) {
        int pow2 = 1;
        while (pow2 <= temp) {pow2 *= 2;}
        pow2--;
        for (int i = temp; pow2-i <= temp; i--) {
            ans[i] = pow2-i;
        }
        temp = pow2-temp-1;
    }
    cout << r*(r+1) << endl;
    for (auto x: ans) {cout << x << " ";}
    cout << endl;
}

signed main() {
    int t; cin >> t;
    while (t--) {solve();}
}