#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long
#define ll long long 
#define f(i, n) for (int i = 0; i < (n); i++)
#define ia(a, n) \
    int a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<int> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define pb push_back
#define ppb pop_back
#define mp make_pair
const int NUM = 1e6 + 5; 
const int N = 1e7 + 5;  
#define sor(v) sort(v.begin(), v.end())
#define rsor(v) sort(v.begin(), v.end(), greater<>())
#define rev(v) reverse(v.begin(), v.end())
#define DEBUG(x) cerr << #x << ": " << x << '\n'
int mod_pow(int a, int b, int m = MOD) {
    int res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
// muruga enna kapathu
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<int>va(n);
    vector<int>vb(m);
    for (ll &i : va) cin >> i;
    for (ll &i : vb) cin >> i;
    sort(vb.begin(), vb.end());
    va.insert(va.begin(), -INF);
    n++;
    for (ll i = 1; i < n; i++) {
        auto it = lower_bound(vb.begin(), vb.end(), -15, [&](ll a, ll _) {
            assert(_ == -15);
            return a-va[i] < va[i-1];
        });
        if (it == vb.end()) continue;
        ll j = *it;
        if (va[i] < va[i-1] && j-va[i] < va[i-1]) continue; // OH MY GOD
        va[i] = min((va[i] < va[i-1] ? INF : va[i]), (j-va[i] < va[i-1] ? INF : j-va[i]));
    }
    cout << (is_sorted(va.begin(), va.end()) ? "YES" : "NO") << '\n';
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
