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
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    iv(p,n);
    bool one=false;
    bool zero=false;
    for(char c:s){
        if(c=='1')one=true;
        else zero=true;
    }
    int curra=0;
    int currb=0;
    int total=0;
    for(int i=0;i<s.size();i++){
        total+=p[i];
        if(s[i]=='1'){
            currb+= (p[i]/2)+1;
        }
        else{
            curra+= (p[i]/2)+1;
        }
    }
    if(curra > x || currb > y){
        no
        return;
    }
    if(total>x+y){
        no
        return;
    }
    if(zero && one){
        yes
        return;
    }
    else{
        if(zero){
            if(x>=y+n) yes
            else no
        }
        else{
            if(y>=x+n) yes
            else no
        }
    }

}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
