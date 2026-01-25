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
int setBitNumber(int n){
    int k = __builtin_clz(n);
    return 1 << (31 - k);
}
void solve() {
    int a,b;
    cin>>a>>b;
    //starting with a
    int mini=0;
    int layers=0;
    int tempa=a;
    int tempb=b;
    for(int i=0;i<=max(a,b);i++){
        if((i+1)&1){
            if(tempa >= pow(2,i)){
                layers++;
                tempa-=pow(2,i);
            }
            else{
                break;
            }
        }
        else{
            if(tempb >= pow(2,i)){
                layers++;
                tempb-=pow(2,i);
            }
            else{
                break;
            }
        }
    }
    int layers2=0;
    tempa=a;
    tempb=b;
    for(int i=0;i<=max(a,b);i++){
        if((i+1)&1){
            if(tempb >= pow(2,i)){
                layers2++;
                tempb-=pow(2,i);
            }
            else{
                break;
            }
        }
        else{
            if(tempa >= pow(2,i)){
                layers2++;
                tempa-=pow(2,i);
            }
            else{
                break;
            }
        }
    }
    cout<<max(layers,layers2)<<endl;
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
