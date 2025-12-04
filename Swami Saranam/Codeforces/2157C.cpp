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
struct Query{
    int c,l,r;
};

void solve() {
    int n,k,q;
    cin>>n>>k>>q;

    vector<Query> queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i].c>>queries[i].l>>queries[i].r;
        queries[i].l--;
        queries[i].r--;
    }

    sort(queries.begin(),queries.end(),[](const Query &a,const Query &b){
        if(a.l!=b.l) return a.l<b.l;
        return a.r<b.r;
    });

    vector<int> a(n,-1);
    vector<int> query_type_map(n,0);

    for(auto &query:queries){
        int c=query.c;
        int l=query.l;
        int r=query.r;
        int previous_type_at_l=query_type_map[l];

        if(c==1){
            if(previous_type_at_l==0||previous_type_at_l==1){
                for(int i=l;i<=r;i++){
                    if(a[i]==-1){
                        a[i]=k;
                        query_type_map[i]=1;
                    }
                }
            }else{
                for(int i=l;i<=r;i++){
                    if(a[i]==-1){
                        a[i]=k;
                        query_type_map[i]=1;
                    }
                }
            }
        }else{
            if(previous_type_at_l==1){
                for(int i=l;i<=r;i++){
                    if(a[i]==k){
                        a[i]=k+1;
                    }
                }
            }
            set<int> needed;
            for(int v=0;v<k;v++) needed.insert(v);
            vector<int> slots;
            for(int i=l;i<=r;i++){
                if(a[i]!=-1) needed.erase(a[i]);
                else slots.push_back(i);
            }
            vector<int> to_place(needed.begin(),needed.end());
            int m=min((int)slots.size(),(int)to_place.size());
            for(int i=0;i<m;i++){
                int idx=slots[i];
                if(a[idx]==-1){
                    a[idx]=to_place[i];
                    query_type_map[idx]=2;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        if(a[i]==-1) a[i]=0;
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<(i+1<n?' ':'\n');
    }
}


signed main() {
    fast();
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
