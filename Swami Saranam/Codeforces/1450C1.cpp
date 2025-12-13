// karthik solving bois
#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   
#define ll long long
#define int long long 
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

ll mod_pow(ll a, ll b, ll m = mod) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
ll mod_inv(ll a, ll m = mod) {
    return mod_pow(a, m - 2, m);
}
ll mod_div(ll a, ll b, ll m = mod) {
    return (a % m * mod_inv(b, m)) % m;
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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}
// thalivare check and write in your note first 
// dont bullshit 
// think propelry 
// solve fast 
// check for cin>>t if that needed or just one testcase 

void solve(){
    int n;cin>>n;
    vector<string> g(n);
    for(int i=0;i<n;i++) cin>>g[i];
    vector<int> cnt(3,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]=='X'){
                cnt[((i-j)%3+3)%3]++;
            }
        }
    }
    int best=0;
    if(cnt[1]<cnt[best]) best=1;
    if(cnt[2]<cnt[best]) best=2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]=='.') continue;
            if(((i-j)%3+3)%3==best) g[i][j]='O';
            else g[i][j]='X';
        }
    }
    for(auto &s:g) cout<<s<<endl;
}


// XX.XXX
// XXXXXX
// XXX.XX
// XXXXXX
// XX.X.X
// XXXXXX

// XX.XXO
// OXXOXX
// XOX.OX
// XXOXXO
// OX.O.X
// XOXXOX

// OX.OXX
// XOXXOX
// XXO.XO
// OXXOXX
// XO.X.X
// XXOXXO


// expected

// XX.XXO
// XOXXOX
// OXX.XX
// XOOXXO
// XX.X.X
// OXXOXX



// OX.OXX
// XOXXOX
// XXO.XO
// OXXOXX
// XO.X.X
// XXOXXO


// .XX.XX
// X0.X.X
// .X0.X0
// 0X.0X.
// .0X.0X
// XX.XX.

// 1 2 3 4 5 6
// 1 2 3
// 2 3 4 
// 3 4 5
// 4 5 6

signed main() {
    fast();
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
