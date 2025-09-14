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
bool lexo(vector<int>a,vector<int>b,int start){
    int n=min(a.size(),b.size());
    for(int i=start;i<n;i++){
        if(a[i]<b[i]) return true;
        if(a[i]>b[i]) return false;
    }
    return a.size()<b.size();
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>>v(n);
    int maxi=0;
    int index=0;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>v[i][j];
        }
        if(k>maxi){
            maxi=k;
            index=i;
        }
    }
    vector<int> ans;
    // // fucking sorting is not wroking 
    // // ll temp=0;
    // // for(ll i=0;i<maxi;i++){
    // //     while(temp<n && v[temp].size()<=i)temp++;
    // //     if(temp==n) break;
    // //     ans.push_back(v[temp][i]);
    // // }
    // // for(auto it:ans){
    // //     cout<<it<<" ";
    // // }
    // // cout<<endl;
    // // vector<int>nums;
    // // for(int i=0;i<n;i++){
    // //     int temp=-1;
    // //     for(int j=0;j<n;j++){
    // //         if(!used[j] && (temp==-1 || lexo(v[j],v[temp])))temp=j;
    // //     }
    // //     nums.push_back(temp);
    // //     used[temp]=true;
    // // }
    // // int temp=0;
    // // for(int i=0;i<maxi;i++){
    // //     while(temp<n && v[nums[temp]].size()<=i)temp++;
    // //     if(temp==n) break;
    // //     ans.push_back(v[nums[temp]][i]);
    // // }
    int start=0;
    while(start<n){
        int temp=-1;
        for(int i=0;i<n;i++){
            if(v[i].size()<=start) continue;
            else{
                if(temp==-1 || lexo(v[i],v[start],start)){
                    temp=i;
                }
            }
        }
        if(temp==-1) break;
        else{
            for(int j=start;j<v[temp].size();j++){
                ans.push_back(v[temp][j]);
            }
        }
        start=v[temp].size();
    }
    vector<int>maximumArr=v[index];
    for(int i=start;i<maximumArr.size();i++){
        ans.push_back(maximumArr[i]);
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    // sort(v.rbegin(),v.rend());
    // for(int i=0;i<v.size();i++){
    //     for(int j=0;j<v[i].size();j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
// 3
// 5 2 4 3 1 3
// 7 7 6 5 4 4 2 1
// 4 2 4 2 1
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
