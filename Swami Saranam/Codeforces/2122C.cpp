#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long
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
#define mp make_pair
#define all(x) (x).begin(),(x).end()
const int NUM = 1e6 + 5; 
const int N = 1e7 + 5;  
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
void solve() {
    int n;cin>>n;int s=0;
    vector<array<int,3> > a(n);for(int i=0;i<n;++i) {cin>>a[i][0]>>a[i][1];a[i][2]=i;}
    sort(all(a));
    vector<int> idx(n),idy(n);
    for(int i=0;i<n/2;++i) {idx[a[i][2]]=1;}
    sort(all(a),[&](array<int,3> u,array<int,3> v) {return u[1]<v[1];});
    for(int i=0;i<n/2;++i) {idy[a[i][2]]=1;}
    vector<int> zx[2][2];
    for(int i=0;i<n;++i) {zx[idx[i]][idy[i]].pb(i);}
    for(int i=0;i<zx[0][0].size();++i) {
        cout<<zx[0][0][i]+1<<' '<<zx[1][1][i]+1<<'\n';
    }
    for(int i=0;i<zx[0][1].size();++i) {
        cout<<zx[0][1][i]+1<<' '<<zx[1][0][i]+1<<'\n';
    }
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
