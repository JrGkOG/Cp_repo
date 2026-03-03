#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long
#define ll long long
#define f(i, n) for (int i = 0; i < (n); i++)
#define ia(a, n) \
    int a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<int> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define pb push_back
#define ppb pop_back
// #define mp make_pair
const int NUM = 1e6 + 5; 
// const int N = 1e7 + 5;  
#define sor(v) sort(v.begin(), v.end())
#define rsor(v) sort(v.begin(), v.end(), greater<>())
#define rev(v) reverse(v.begin(), v.end())
#define DEBUG(x) cerr << #x << ": " << x << '\n'
int mod_pow(int a, int b, int m = MOD) {
    int res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
// muruga enna kapathu
const int N=2000000;
 
ll i,j,k,n,m,t;
ll a[N+50],b[N+50],sima[N+50];
 
map<ll,basic_string<ll> > mp;
void solve() {
    cin>>n>>m>>i;
    ll res=n;
    for(i=1;i<=n;i++){cin>>a[i]; sima[i]=0;}
    for(i=1;i<=m;i++)cin>>b[i];
    sort(a+1,a+n+1); sort(b+1,b+m+1);
    mp={};
    j=0; b[0]=-1e18; b[m+1]=1e18;
    for(i=1;i<=n;i++){
        while(j<=m&&b[j+1]<a[i])j++;
        mp[b[j]-a[i]]+=i; mp[b[j+1]-a[i]]+=i;
    }
    string s; k=0;
    cin>>s;
    for(auto c:s){
        if(c=='R')k++;
        else k--;
        for(auto i:mp[k]){
            res-=!sima[i]; sima[i]=1;
        }
        mp[k]={};
        cout<<res<<' ';
    }
    cout<<'\n';
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
