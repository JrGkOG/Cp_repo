#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);

unordered_map<string, ll> dp;

ll f(vector<ll>& nums, ll node, ll prev, ll length) {
    if (node < 0) {
        return (length >= 3) ? 1 : 0;
    }
    string key = to_string(node) + "," + to_string(prev) + "," + to_string(length);
    if (dp.find(key) != dp.end()) return dp[key];
    ll no = f(nums, node - 1, prev, length);
    ll yes = 0;
    if (nums[node] < prev) {
        yes = f(nums, node - 1, nums[node], length + 1);
    }

    return dp[key] = yes + no;
}

void func() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        vector<ll> nums(x);
        for (ll i = 0; i < x; i++) {
            cin >> nums[i];
        }
        dp.clear();
        ll ans = f(nums, x - 1, LLONG_MAX, 0);
        cout << ans << endl;
    }
}
int main(){
    func();
    return 0;
}