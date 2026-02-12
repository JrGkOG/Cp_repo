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
bool is2by3(int a,int b){
    if(a<=0 || b<=0) return false;
    int gcdd=gcd(a,b);
    return ((a/gcdd) ==2 && (b/gcdd)==3);
}
void solve() {
    int a,b;
    cin>>a>>b;
    int redA=a/(gcd(a,b));
    int redB=b/(gcd(a,b));
    if(a==2 && b==3){
        cout<<"Bob"<<endl;
        return;
    }
    // if(redA==2 && redB==3){
    //     cout<<"Bob"<<endl;
    //     return;
    // }
    // bool flag=false;
    // if(redA>0){
    //     if(is2by3(redA-1,redB)){
    //         flag=true;
    //     }
    // }
    // if(redB>1){
    //     if(is2by3(redA,redB-1)){
    //         flag=true;
    //     }
    // }
    // if(flag) cout<<"Bob"<<endl;
    // else cout<<"Alice"<<endl;
    if(3*a<2*b){
        cout<<"Alice"<<endl;
        return;
    }
    // else{
    //     int mini=min(a/2,b/3);
    //     if(mini==0){
    //         cout<<"Alice"<<endl;
    //         return;
    //     }
    //     int maxi=(a-(2*mini))+(b-(3*mini));
    //     // if(maxi&1){
    //     //     cout<<"Alice"<<endl;
    //     // }
    //     // else{
    //     //     cout<<"Bob"<<endl;
    //     // }
    //     // if(maxi>1){
    //     //     cout<<"Bob"<<endl;
    //     // }
    //     // else{
    //     //     if((a+b-5)&1){
    //     //         cout<<"Alice"<<endl;
    //     //     }
    //     //     else{
    //     //         cout<<"Bob"<<endl;
    //     //     }
    //     // }
    // }
    else if(a<b && 3*a>=2*b){
        cout<<"Bob"<<endl;
    }
    else{
        cout<<"Alice"<<endl;
    }
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
