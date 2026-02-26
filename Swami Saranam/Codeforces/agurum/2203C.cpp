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
#define INF 1000000000000000000int
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
vector<int>extractBits(int m){
    vector<int>bits;
    for(int i=60;i>=0;i--){
        if((m>>i)&1LL){
            bits.push_back(i);
        }
    }
    return bits;
}
bool canForm(int s,const vector<int>&bits,int m,int n){
    if(s==0) return true;
    if(n==0) return false;
    bool flag=true;
    if(n<floor(s/m)) return false;
    int rem=s;
    for(int bit:bits){
        int canTake=rem>>bit;
        int take=min(n,canTake);
        rem-=(take<<bit);
        if(rem==0){
            break;
        }
    }
    if(rem!=0) flag=false;
    return flag;
}
int seqLength(int s,int m){
    if(__builtin_ctzll(s)<__builtin_ctzll(m)) return -1;
    vector<int>bits=extractBits(m);
    if(canForm(s,bits,m,s)==false) return -1;
    int low=1,high=s,ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canForm(s,bits,m,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
void solve(){
    int s,m;
    cin>>s>>m;
    if(s==0) cout<<0<<endl;
    else if(m==0) cout<<-1<<endl;
    else if(s==m) cout<<1<<endl;
    else cout<<seqLength(s,m)<<endl;
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
