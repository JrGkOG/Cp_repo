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
#define DEBUG(x) cerr << #x << ": " << x << endl
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
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    string x;cin>>x;

    vector<int> s(n,0);
    vector<pair<int,int>> ops;

    vector<int> need;
    for(int i=0;i<n;i++){
        if(x[i]=='1') need.push_back(i);
    }

    if(need.empty()){
        cout<<0<<'\n';
        return;
    }

    int L=n,R=-1;

    for(int k:need){
        int lk=-1,rk=-1;

        for(int i=k-1;i>=0;i--){
            if(p[i]<p[k]){lk=i;break;}
        }
        for(int i=k+1;i<n;i++){
            if(p[i]>p[k]){rk=i;break;}
        }

        if(lk==-1 || rk==-1){
            cout<<-1<<'\n';
            return;
        }

        L=min(L,lk);
        R=max(R,rk);
    }

    ops.push_back({L+1,R+1});

    for(int i=L+1;i<R;i++){
        if(min(p[L],p[R])<p[i] && p[i]<max(p[L],p[R])){
            s[i]=1;
        }
    }

    for(int k:need){
        if(s[k]==0){
            int lk=-1,rk=-1;
            for(int i=k-1;i>=0;i--){
                if(p[i]<p[k]){lk=i;break;}
            }
            for(int i=k+1;i<n;i++){
                if(p[i]>p[k]){rk=i;break;}
            }
            if(lk==-1 || rk==-1){
                cout<<-1<<'\n';
                return;
            }
            ops.push_back({lk+1,rk+1});
            if(ops.size()>5){
                cout<<-1<<'\n';
                return;
            }
            for(int i=lk+1;i<rk;i++){
                if(min(p[lk],p[rk])<p[i] && p[i]<max(p[lk],p[rk])){
                    s[i]=1;
                }
            }
            s[k]=1;
        }
    }

    cout<<ops.size()<<'\n';
    for(auto &q:ops) cout<<q.first<<" "<<q.second<<'\n';
}


signed main() {
    fast();
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
