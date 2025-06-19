#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 998244353;

ll mod_pow(ll x, ll M) {
    ll res = 1, base = 2;
    while (x > 0) {
        if (x % 2 == 1)
            res = (res * base) % M;
        base = (base * base) % M;
        x /= 2;
    }
    return res;
}

void func() {
    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        vector<pair<ll, ll>> nums1, nums2;
        ll prev = LLONG_MIN;
        ll index = 0;

        // First sequence
        for(ll i = 0; i < x; i++) {
            ll num;
            cin >> num;
            if(num > prev) {
                nums1.push_back({num, i});
                prev = num;
                index = i;
            } else {
                nums1.push_back({num, index});
            }
        }

        // Second sequence
        prev = LLONG_MIN;
        index = 0;
        for(ll i = 0; i < x; i++) {
            ll num;
            cin >> num;
            if(num > prev) {
                nums2.push_back({num, i});
                prev = num;
                index = i;
            } else {
                nums2.push_back({num, index});
            }
        }

        for(ll i = 0; i < x; i++) {
            ll idx1 = nums1[i].second;
            ll idx2 = nums2[i].second;

            if(nums1[idx1].first > nums2[idx2].first) {
                ll ans = (mod_pow(nums1[idx1].first, mod) + mod_pow(nums2[i - idx1].first, mod)) % mod;
                cout << ans%mod << " ";
            }
            else if(nums1[idx1].first < nums2[idx2].first) {
                ll ans = (mod_pow(nums2[idx2].first, mod) + mod_pow(nums1[i - idx2].first, mod)) % mod;
                cout << ans%mod << " ";
            }
            else {
                ll ans1 = (mod_pow(nums1[idx1].first, mod) + mod_pow(max(nums2[i - idx1].first, nums1[i - idx2].first), mod)) % mod;
                cout << ans1%mod << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    func();
    return 0;
}
