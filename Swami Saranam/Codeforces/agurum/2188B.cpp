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
    string s;
    cin>>s;
    if(s=="0"){
        cout<<1<<endl;
        return;
    }
    vector<int>vis(n,0);
    int init=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            init++;
            vis[i]=1;
            if(i-1>=0){
                vis[i-1]=1;
            }
            if(i+1<n){
                vis[i+1]=1;
            }
        }
    }
    // int counter=0;
    // for(int i=0;i<n;i++){
    //     if(vis[i]==0){
    //         counter++;
    //     }
    // }

    // int total=0;
    // if(counter==1){
    //     total+=1+init;
    // }
    // else{
    //     total +=ceil(counter/2)+init;
    // }
    // cout<<total<<endl;
    int total=init;
    int curr=0;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            curr++;
        }
        else{
            cout<<curr<<endl;
            if(curr>0){
                total+=(curr+2)/3;  
            }
            curr=0;
        }
    }
    if(curr>0){
        total+=(curr+2)/3;
    }
    cout<<total<<endl;
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
