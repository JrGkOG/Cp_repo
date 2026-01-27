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
    int n;cin>>n;
    string s;cin>>s;
    vector<int> ones;
    for(int i=0;i<n;i++){
        if(s[i]=='1') ones.push_back(i);
    }
    if(ones.size()==n){
        cout<<0<<endl; 
        return; 
    }
    int ans=0;
    for(int z=0;z<n;z++){
        if(s[z]=='0'){
            auto it=upper_bound(ones.begin(),ones.end(),z);
            int p;
            if(it==ones.begin()) p=ones.back();
            else{ 
                it--;
                p=*it;
            }
            int d=(z-p+n)%n;
            if(d==0) d=n;
            ans=max(ans,d);
        }
    }
    cout<<ans<<endl;
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
