#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long
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
const int MAXN = 500005;
int n, t[4*MAXN], arr[MAXN], ind[MAXN], ans;
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max (t[v*2], t[v*2+1]);
    }
}
int maxx (int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max (maxx(v*2, tl, tm, l, min(r, tm)), 
                maxx(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void rec (int l, int r, int tot){
    int mm = maxx (1, 0, n - 1, l, r);
    if (mm){
        int p = ind[mm];
        if (p < r) rec (p + 1, r, tot + 1);
        if (p > l) rec (l, p - 1, tot + 1);
        ans = max (ans, tot);
    }
}
// muruga enna kapathu
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        ind[arr[i]] = i;
    }
    ans = 0;
    build (arr, 1, 0, n - 1);
    rec (0, n - 1, 1);
    cout << n - ans << '\n';
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
