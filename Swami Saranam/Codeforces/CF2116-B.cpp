#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll a, ll b) {
    ll res = 1;
    while(b > 0) {
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll mod = 998244353;
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
                ll ans = power(2LL, nums1[idx1].first) + power(2LL, nums2[i - idx1].first);
                cout << ans%mod << " ";
            }
            else if(nums1[idx1].first < nums2[idx2].first) {
                ll ans = power(2LL, nums2[idx2].first) + power(2LL, nums1[i - idx2].first);
                cout << ans%mod << " ";
            }
            else {
                ll ans1 = power(2LL, nums1[idx1].first) + power(2LL, max(nums2[i - idx1].first,nums1[i - idx2].first));
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