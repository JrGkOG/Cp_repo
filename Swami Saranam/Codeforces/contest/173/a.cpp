#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

ll maxCoins(ll n) {
    ll total_coins = 1;
    while (n > 3) {
        total_coins *= 2; // Each transformation gives us 2 coins
        n /= 4; // Reduce n to the new value
    }
    return total_coins;
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << maxCoins(n) << endl;
    }
    return 0;
}