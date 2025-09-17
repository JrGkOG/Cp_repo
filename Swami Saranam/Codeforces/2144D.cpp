// karthik solving bois
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
#define MAX_PRICE 2*1e5
void solve() {
    ll n,y;
    cin>>n>>y;
    ll max_c=0;
    vector<ll>initial_counts(MAX_PRICE+1,0);
    for(ll i=0;i<n;++i){
        ll price;
        cin>>price;
        initial_counts[price]++;
        max_c=max(max_c,price);
    }
    vector<ll>prefix_counts(max_c+2,0);
    for(ll i=1;i<=max_c+1;++i){
        prefix_counts[i]=prefix_counts[i-1]+initial_counts[i-1];
    }
    ll max_income=-5e18;
    for(ll x=2;x<=max_c+1;++x){
        ll current_total_value=0;
        ll total_reused_tags=0;
        for(ll j=x;j<=max_c+(x-1);j+=x){
            ll new_price=j/x;
            ll lower_bound_exclusive=j-x;
            ll upper_bound_inclusive=min(max_c,j);
            if(upper_bound_inclusive<=lower_bound_exclusive)continue;
            ll num_items_in_range=prefix_counts[upper_bound_inclusive+1]-prefix_counts[lower_bound_exclusive+1];
            if(num_items_in_range>0){
                current_total_value+=new_price*num_items_in_range;
                if(new_price<=max_c)total_reused_tags+=min(initial_counts[new_price],num_items_in_range);
            }
        }
        ll tags_to_print=n-total_reused_tags;
        ll printing_cost=tags_to_print*y;
        ll current_income=current_total_value-printing_cost;
        max_income=max(max_income,current_income);
    }
    cout<<max_income<<endl;
}
signed main() {
    fast();
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
