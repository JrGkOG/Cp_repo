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
#define INF 1000000000000000000LL 
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

void func(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
    cin >> n >> k;
    ia(a,n);
    set<pair<ll,ll>> s;
    f(i,n) {
        ll j = 0;
        while((1LL<<j) & a[i]) {
            j++;
        }
        s.insert(mp(1LL<<j, i));
    }
    ll ans = 0;
    f(i,n) {
        ans += __builtin_popcountll(a[i]);
    }
    while(k > 0) {
        if(s.begin()->first <= k) {
            k -= s.begin()->first;
            a[s.begin()->second] |= s.begin()->first;
            ans++;
            ll idx = s.begin()->second;
            s.erase(s.begin());
 
            ll j = 0;
            while((1LL<<j) & a[idx]) {
                j++;
            }
            s.insert(mp(1LL<<j, idx));
        }
        else break;
    }
    cout << ans << nline;
    }
}
int main(){
    fast();
    func();
    return 0;
}