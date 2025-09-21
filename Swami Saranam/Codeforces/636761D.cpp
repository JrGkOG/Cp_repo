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

void solve() {
    int n,k,q;
    cin>>n>>k>>q;

    vector<pair<int,int>> t(n);
    int tot=0;
    for(int i=0;i<n;i++){
        cin>>t[i].first>>t[i].second;
        tot+=t[i].second;
    }

    map<int,vector<pair<int,int>>> qd;
    int mxD=0;
    for(int i=0;i<q;i++){
        int d,y;
        cin>>d>>y;
        qd[d].push_back({y-1,i});
        mxD=max(mxD,d);
    }
    
    vector<pair<int,int>> ans(q);
    int back=0;
    bool stop=false;

    for(int day=1;day<=mxD&&!stop;day++){
        int lst=t[n-1].first;
        if(tot>k&&back>=lst){
            for(auto&[qdv,qs]:qd){
                if(qdv>=day){
                    int diff=qdv-day;
                    int curB=back+diff*(tot-k);
                    for(auto&qu:qs){
                        int ti=qu.first,qi=qu.second;
                        int fin=curB;
                        for(int i=0;i<=ti;i++) fin+=t[i].second;
                        int fD=qdv+(fin-1)/k;
                        int fH=(fin-1)%k+1;
                        ans[qi]={fD,fH};
                    }
                }
            }
            stop=true;
            break;
        }

        int curF=back;
        if(qd.count(day)){
            for(int i=0;i<n;i++){
                int arr=t[i].first-1;
                curF=max(curF,arr)+t[i].second;
            }
            for(auto&qu:qd[day]){
                int ti=qu.first,qi=qu.second;
                int tmp=back;
                for(int i=0;i<=ti;i++){
                    tmp=max(tmp,t[i].first-1)+t[i].second;
                }
                int fD=day+(tmp-1)/k;
                int fH=(tmp-1)%k+1;
                ans[qi]={fD,fH};
            }
        }else{
            for(int i=0;i<n;i++){
                int arr=t[i].first-1;
                curF=max(curF,arr)+t[i].second;
            }
        }
        back=max(0LL,curF-k);
    }

    for(int i=0;i<q;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
// 