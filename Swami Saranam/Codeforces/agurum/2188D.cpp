#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

map<pair<int, pair<ll, ll>>, pair<ll, pair<ll, ll>>> memo;


void solve() {
    ll x, y;
    cin >> x >> y;
    
    ll p = 0, q = 0;
    for (int i = 30; i >= 0; i--) {
        int xi = (x >> i) & 1;
        int yi = (y >> i) & 1;
        
        if (xi == 1 && yi == 1) {
            // Conflict: We give the bit to the number that is currently "closer" 
            // to its target, or we use the DP to decide.
            // For Codeforces D, often the greedy choice is: 
            // Give it to the one that results in a smaller total distance.
            if (abs((p | (1LL << i)) - x) + abs(q - y) < abs(p - x) + abs((q | (1LL << i)) - y)) {
                p |= (1LL << i);
            } else {
                q |= (1LL << i);
            }
        } else {
            if (xi) p |= (1LL << i);
            if (yi) q |= (1LL << i);
        }
    }
    cout << p << " " << q << endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}