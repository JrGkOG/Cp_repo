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
    int n;
    cin>>n;
    priority_queue<int> odd,even;
    iv(v,n);
    for(int i=0;i<n;i++){
        if(v[i]&1) odd.push(v[i]);
        else even.push(v[i]);
    }
    int cntOdd=odd.size();
    int cntEven=even.size();

    vector<int> evenList;
    while(!even.empty()){
        evenList.push_back(even.top());
        even.pop();
    }
    vector<int> evenPref(cntEven+1);
    for(int i=1;i<=cntEven;i++) evenPref[i]=evenPref[i-1]+evenList[i-1];
    vector<int> ans(n+1);
    for(int k=1;k<=n;k++){
        int ce=min(k-1,cntEven);
        int co=k-ce;
        if(co%2==0){
            ce--;
            co++;
        }
        if(ce<0||co<1||co>cntOdd){
            ans[k]=0;
            continue;
        }
        int bestOdd=odd.top();
        int need=ce;
        int sumEven=0;
        // vector<int> temp1;
        // while(need>0){
        //     int x=even.top();
        //     even.pop();
        //     temp1.push_back(x);
        //     sumEven+=x;
        //     need--;
        // }
        // for(int x:temp1) even.push(x);
        sumEven = evenPref[ce];
        ans[k]=bestOdd+sumEven;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}


signed main() {
    fast();
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define int long long
// #define f(a,b) for(int i=a;i<=b;i++)
// #define v(a) vector<a>
// #define srt(v) sort(v.begin(),v.end())
// #define rsrt(v) sort(v.begin(),v.end(),greater<int>())
// #define vv(a) vector<vector<a> >
// #define af(v) for(auto &it:v)

// v(int) prefix(v(int)& arr) {
//     int n = arr.size();
//     v(int) pre(n+1, 0);
//     f(0,n-1) pre[i+1] = pre[i] + arr[i];
//     return pre;
// }

// vv(int) prefixSum2D(vv(int)& mat) {
//     int n = mat.size();
//     int m = mat[0].size();
//     vv(int) pre(n+1, v(int)(m+1, 0));
//     for(int i=1; i<=n; i++) {
//         for(int j=1; j<=m; j++) {
//             pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];

//         }
//     }
//     return pre;
// }

// int gcd(int a, int b) {
//     while (b) {
//         a %= b;
//         swap(a, b);
//     }
//     return a;
// }

// int lcm(int a, int b) {
//     return (a / gcd(a, b)) * b;
// }


// void solve(){
//     int n;
//     cin>>n;
//     v(int) even,odd;
//     f(0,n-1){
//         int temp;
//         cin>>temp;
//         if(temp&1)odd.push_back(temp);
//         else even.push_back(temp);
//     }
//     rsrt(odd);
//     rsrt(even);
//     v(int) prereven=prefix(even);
//     v(int) ans(n);
//     if(odd.size()==0){
//         f(0,n-1){
//             cout<<0<<" ";
//         }
//         cout<<endl;
//         return;
//     }
//     int eve=even.size();
//     int od=odd.size();
//     if(eve==0 && od==1){
//         cout<<odd[0]<<endl;
//         return;
//     }
//     if(eve==0){
//         bool flag2=false;
//         if(odd.size()%2==0){
//             flag2=true;
//         }
//         if(flag2==true){
//             bool flag=1;
//             f(0,n-1){
//                 if(flag){
//                     ans[i]=odd[0];
//                     flag^=1;
//                 }
//                 else{
//                     ans[i]=0;
//                     flag^=1;
//                 }
//             }
//             f(0,n-2){
//                 cout<<ans[i]<<" ";
//             }
//             cout<<0<<" ";
//             cout<<endl;
//             return;
//         }
//         bool flag=1;
//         f(0,n-1){
//             if(flag){
//                 ans[i]=odd[0];
//                 flag^=1;
//             }
//             else{
//                 ans[i]=0;
//                 flag^=1;
//             }
//         }
//         f(0,n-1){
//             cout<<ans[i]<<" ";
//         }
//         cout<<endl;
//         return;
//     }
//     if(eve==1){
//         if(odd.size()%2==0){
//             ans[0]=odd[0];
//             ans[1]=odd[0]+even[0];
//             bool flag=1;
//             f(2,n-1){
//                 if(flag){
//                     ans[i]=odd[0];
//                     flag^=1;
//                 }
//                 else{
//                     ans[i]=ans[1];
//                     flag^=1;
//                 }
//             }
//             f(0,n-2){
//                 cout<<ans[i]<<" ";
//             }
//             cout<<0<<" ";
//             cout<<endl;
//             return;
//         }
//         else{
//             ans[0]=odd[0];
//             ans[1]=odd[0]+even[0];
//             bool flag=1;
//             f(2,n-1){
//                 if(flag){
//                     ans[i]=odd[0];
//                     flag^=1;
//                 }
//                 else{
//                     ans[i]=ans[1];
//                     flag^=1;
//                 }
//             }
//             f(0,n-1){
//                 cout<<ans[i]<<" ";
//             }
//             cout<<endl;
//             return;
//         }
//     }
//     if(odd.size()%2==0){
//         f(0,eve){
//             int temp=i+1;
//             int temp2=0;
//             if(temp==1){
//                 ans[0]=odd[0];
//             }
//             else{
//                 temp2+=odd[0];
//                 temp--;
//                 if(temp<=eve){
//                     temp2+=prereven[temp];
//                 }
//                 ans[i]=temp2;
//             }
//         }
//         int rest1=ans[eve];
//         int rest2=rest1-even[eve-1];
//         bool flag=1;
//         f(eve+1,n-1){
//             if(flag){
//                 ans[i]=rest2;
//                 flag^=1;
//             }
//             else{
//                 ans[i]=rest1;
//                 flag^=1;
//             }
//         }
//         f(0,n-2){
//             cout<<ans[i]<<" ";
//         }
//         cout<<0<<endl;
//         cout<<endl;
//         return;
//     }
//     f(0,eve){
//             int temp=i+1;
//             int temp2=0;
//             if(temp==1){
//                 ans[0]=odd[0];
//             }
//             else{
//                 temp2+=odd[0];
//                 temp--;
//                 if(temp<=eve){
//                     temp2+=prereven[temp];
//                 }
//                 ans[i]=temp2;
//             }
//     }
//     int rest1=ans[eve];
//     int rest2=rest1-even[eve-1];
//     bool flag=1;
//     f(eve+1,n-1){
//         if(flag){
//             ans[i]=rest2;
//             flag^=1;
//         }
//         else{
//             ans[i]=rest1;
//             flag^=1;
//         }
//     }
//     f(0,n-1){
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;
// }
// signed main(){
//     int t;
//     cin>>t;
//     while(t--) solve();
//     return 0;
// }