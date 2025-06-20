#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   
#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"
void func(){
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin >> x;
        vector<int> res(31, 0);
        for (int i = 0; i < 30; i++) {
            if (1ll & (x >> i)) {
                if (res[i]) {
                    res[i + 1] = 1;
                    res[i] = 0;
                } else if (i > 0) {
                    if (res[i - 1] == 1) {
                        res[i + 1] = 1;
                        res[i - 1] = -1;
                    } else {
                        res[i] = 1;
                    }
                } else if (i == 0) {
                    res[i] = 1;
                }
            }
        }
        cout << 31 << '\n';
        for (int i = 0; i <= 30; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
}
int main(){
    fast();
    func();
    return 0;
}