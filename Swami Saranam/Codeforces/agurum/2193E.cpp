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
    int n;
    cin>>n;
    iv(v,n);
    set<int>mul;
    bool flag=false;
    for(int i=0;i<n;i++){
        if(v[i]==1) flag=true;
        if(v[i]>1 && v[i]<=n) mul.insert(v[i]);
    }
    vector<int>multi(mul.begin(),mul.end());
    vector<int>dp(n+1,LLONG_MAX);
    int maxi=0;
    if(flag){
        dp[1]=1;
        maxi=1;
    }
    for(int i=0;i<multi.size();i++){
        dp[multi[i]]=1;
        maxi=max(multi[i],maxi);
    }
    if(multi.size()==0){
        if(flag==true) cout<<1<<" ";
        else cout<<-1<<" ";
        for(int i=1;i<n;i++) cout<<-1<<" ";
        cout<<endl;
        return;
    }
    int mini=multi[0];
    for(int i=1;i<=maxi;i++){
        if(i*mini>n) break;
        if(dp[i]==LLONG_MAX) continue;
        for(int j=0;j<multi.size();j++){
            int temp=i*multi[j];
            if(temp>n) break;
            else{
                if(dp[i]+1<dp[temp]){
                    dp[temp]=dp[i]+1;
                    maxi=max(maxi,temp);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dp[i]==LLONG_MAX){
            cout<<-1<<" ";
        }
        else{
            cout<<dp[i]<<" ";
        }
    }
    cout<<endl;
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}