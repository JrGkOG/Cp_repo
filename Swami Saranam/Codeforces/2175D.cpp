// karthik solving bois
#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   
#define ll long long
#define int long long 
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(v, n) \
    ll v[n];     \
    f(i, n) cin >> v[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll NUM = 1e6 + 5; 
const ll N = 1e7 + 5;  
#define DEBUG(x) cerr << #x << ": " << x << '\n'
vector<ll> fact, invfact, power, sieve, lp, primes;
vector<vector<pair<ll,ll>>> adj;
vector<vector<ll>> adj_unweighted;
vector<ll> dist;
vector<bool> visited;

ll mod_pow(ll v, ll b, ll m = mod) {
    ll res = 1;
    v %= m;
    while (b) {
        if (b & 1) res = (res * v) % m;
        v = (v * v) % m;
        b >>= 1;
    }
    return res;
}
ll mod_inv(ll v, ll m = mod) {
    return mod_pow(v, m - 2, m);
}
ll mod_div(ll v, ll b, ll m = mod) {
    return (v % m * mod_inv(b, m)) % m;
}
void init_factorials(ll max_n = NUM) {
    fact.resize(max_n);
    invfact.resize(max_n);
    fact[0] = invfact[0] = 1;
    for (ll i = 1; i < max_n; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    invfact[max_n - 1] = mod_inv(fact[max_n - 1]);
    for (ll i = max_n - 2; i >= 1; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
}
ll combination(ll n, ll k) {
    if (k > n || k < 0) return 0;
    return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}
void init_powers(ll x, ll max_n = NUM) {
    power.resize(max_n);
    power[0] = 1;
    for (ll i = 1; i < max_n; i++)
        power[i] = (power[i - 1] * x) % mod;
}
void calc_sieve(ll max_n = NUM) {
    sieve.assign(max_n + 1, 0);
    for (ll i = 2; i <= max_n; ++i) {
        if (!sieve[i]) {
            for (ll j = i; j <= max_n; j += i)
                if (!sieve[j]) sieve[j] = i;
        }
    }
}
void linear_sieve(ll max_n = N) {
    lp.assign(max_n + 1, 0);
    for (ll i = 2; i <= max_n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.pb(i);
        }
        for (ll j = 0; j < sz(primes) && primes[j] <= lp[i] && i * primes[j] <= max_n; ++j)
            lp[i * primes[j]] = primes[j];
    }
}

ll gcd(ll v, ll b) {
    return b ? gcd(b, v % b) : v;
}
ll lcm(ll v, ll b) {
    return (v / gcd(v, b)) * b;
}
// thalivare check and write in your note first 
// dont bullshit 
// think propelry 
// solve fast 
// check for cin>>t if that needed or just one testcase 
void solve(){
    int n,k;cin>>n>>k;
    iv(v,n);

    vector<vector<ll>> dp(k+1,vector<ll>(k+1,-INF));
    dp[0][0]=0;

    for(int i=0;i<n;i++){
        vector<vector<ll>> newDp(k+1,vector<ll>(k+1,-INF));

        for(int j=0;j<=k;j++){

            // give 0 cards
            for(int mx=0;mx<=k;mx++){
                if(dp[j][mx]==-INF) continue;
                newDp[j][mx]=max(newDp[j][mx],dp[j][mx]+mx);
            }
            ll prefMax=-INF;
            int maxX=min(v[i],k-j);

            for(int x=1;x<=maxX;x++){
                prefMax=max(prefMax,dp[j][x-1]);
                if(prefMax==-INF) continue;
                newDp[j+x][x]=max(newDp[j+x][x],prefMax+x);
            }
        }
        dp.swap(newDp);
    }

    ll ans=0;
    for(int j=0;j<=k;j++){
        for(int mx=0;mx<=k;mx++){
            ans=max(ans,dp[j][mx]);
        }
    }
    cout<<ans<<endl;
}

signed main() {
    fast();
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
