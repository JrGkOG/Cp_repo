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
int getClosestMirror(int x, vector<int>& arr) {
    if (arr.empty()) return -1;
    int m = 0;
    while ((1 << (m + 1)) <= x) m++;
    int i = x - (1 << m);
    int target = (1 << m) - i - 1;
    int closest = arr[0];
    int minDiff = abs(arr[0] - target);
    for (int num : arr) {
        int diff = abs(num - target);
        if (diff < minDiff) {
            minDiff = diff;
            closest = num;
        }
    }
    auto it = find(arr.begin(), arr.end(), closest);
    if (it != arr.end()) arr.erase(it);
    return closest;
}
void solve2() {
    int l,r;
    cin>>l>>r;
    int n=r-l+1;
    int templ=l;
    int tempr=r;
    vector<int>nums1(n);
    vector<int>nums2(n);
    int maxi=0;
    vector<int>avail;
    for(int i=l;i<=r;i++){
        avail.pb(i);
    }
    for(int i=0;i<n;i++){
        nums1[i]=templ;
        nums2[i]=templ;
        templ++;
        maxi+=nums1[i]+nums2[i];
    }
    // so we need to minimuze the bitwaise and between two arrays 
    vector<int>tempb=avail;
    reverse(tempb.begin(),tempb.end());
    // for(int i=0;i<n;i++){
    //     maxi+=2*tempb[i];
    // }
    stack<int>ans;
    for(int b:tempb){
        int possible=getClosestMirror(b,avail);
        maxi-=(b&possible);
        ans.push(possible);
    }
    cout<<maxi<<endl;
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;
}
void optim(int l,int r,vector<int>&ans){
    if (r == -1) {
		return;
	}
	if (r == 0) {
		ans[0] = 0;
		return;
	}
	ll x =(log2(r));
	ll p = (1LL << x) - 1;
	ll rem = r - p;
	for (ll i = 0; i < rem; i++) {
		ans[i + p + 1] = p - i;
	}
	ll pos = p - rem + 1;
	for (ll i = pos; i <= p; i++) {
		ans[i] = r - (i - pos);
	}
	optim(l, pos - 1,ans);
}
void solve(){
    int l,r;
    cin>>l>>r;
    int n=r-l+1;
    vector<int>ans(n,-1);
    optim(l,r,ans);
    int value=0;
    for(int i=0;i<n;i++){
        value += i|ans[i];
    }
    cout<<value<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

}
signed main(){
    fast();
    ll t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
