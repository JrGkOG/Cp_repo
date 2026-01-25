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
int getIdx(vector<int> &a,int v){
    auto it = lower_bound(a.begin(),a.end(),v);
    if(it!=a.end() && *it==v) return it - a.begin();
    return -1;
}
void solve(){
    int n,k; cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    int m = a.size();

    vector<bool> visited(m,false);
    vector<int> b;

    for(int i=0;i<m;i++){
        if(visited[i]) continue;
        int x = a[i];
        bool flag = true;

        if(k/x > m) flag = false;
        else{
            for(int j=1;;j++){
                int v = x * j;
                if(v > k) break;
                if(getIdx(a,v) == -1){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag){
            cout<<-1<<endl;
            return;
        }
        b.push_back(x);
        for(int j=1;;j++){
            int v = x * j;
            if(v > k) break;
            if(v > a.back()) break;
            int idx = getIdx(a,v);
            if(idx != -1) visited[idx] = true;
        }
    }
    cout<<b.size()<<endl;
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<(i+1==b.size()?"":" ");
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
