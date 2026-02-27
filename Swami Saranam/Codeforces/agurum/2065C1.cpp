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
// muruga enna kapathu
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int j = 0; j < m; j++){
        cin >> b[j];
    }
    sort(b.begin(), b.end());

    int cur = -INF;
    bool possible = true;
    for (int i = 0; i < n; i++){
        int cand1 = INF, cand2 = INF;
        if(a[i] >= cur) {
            cand1 = a[i];
        }
        int key = cur + a[i];
        auto it = lower_bound(b.begin(), b.end(), key);
        if(it != b.end()){
            cand2 = (*it) - a[i];
        }

        int chosen = min(cand1, cand2);
        if(chosen == INF){
            possible = false;
            break;
        }
        cur = chosen;
    }
    if(possible) yes
    else no
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
