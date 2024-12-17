#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll lcmArray(vector<ll>& array) {
    ll ans = array[0];
    for (size_t i = 1; i < array.size(); i++) {
        ans = (array[i] * ans) / gcd(array[i], ans);
        if (ans > LLONG_MAX / array[i]) break; 
    }
    return ans;
}
ll numDiv(ll l, ll r, ll n) {
    if (n == 0) return 0;
    ll x = l % n == 0 ? l / n : l / n + 1;
    ll y = r / n;
    return y - x + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll l, r, a, d;
        cin >> l >> r >> a >> d;
        ll n[5];
        for (int i = 0; i < 5; i++) {
            n[i] = a + i * d;
        }

        ll ans = 0;
        for (int i = 0; i < 5; i++) {
            ans += numDiv(l, r, n[i]);
        }
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                vector<ll> lcm_arr = {n[i], n[j]};
                ll lcm = lcmArray(lcm_arr);
                ans -= numDiv(l, r, lcm);
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {
                    vector<ll> lcm_arr = {n[i], n[j], n[k]};
                    ll lcm = lcmArray(lcm_arr);
                    ans += numDiv(l, r, lcm);
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {
                    for (int m = k + 1; m < 5; m++) {
                        vector<ll> lcm_arr = {n[i], n[j], n[k], n[m]};
                        ll lcm = lcmArray(lcm_arr);
                        ans -= numDiv(l, r, lcm);
                    }
                }
            }
        }
        vector<ll> lcm_arr(n, n + 5);
        ll lcm = lcmArray(lcm_arr);
        ans += numDiv(l, r, lcm);
        cout << (r - l + 1) - ans << endl;
    }

    return 0;
}
