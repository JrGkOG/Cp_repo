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
bool cmp(const vector<int>& a,const vector<int>& b,const unordered_set<int>& exists){
    int i=0,j=0;
    while(true){
        while(i<a.size()&&exists.count(a[i]))i++;
        while(j<b.size()&&exists.count(b[j]))j++;
        if(i==a.size()||j==b.size())break;
        if(a[i]!=b[j])return a[i]<b[j];
        i++;j++;
    }
    return (a.size()-i)<(b.size()-j);
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>>blogs(n);
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        vector<int>temp(l);
        for(int j=0;j<l;j++)cin>>temp[j];
        unordered_set<int>seen;
        vector<int>uniqueRev;
        for(int j=l-1;j>=0;j--){
            if(!seen.count(temp[j])){
                seen.insert(temp[j]);
                uniqueRev.push_back(temp[j]);
            }
        }

        blogs[i]=uniqueRev;
    }
    vector<int>ans;
    unordered_set<int>exists;
    vector<int>used(n,0);
    for(int i=0;i<n;i++){
        int best=-1;
        for(int i=0;i<n;i++){
            if(used[i])continue;
            if(best==-1||cmp(blogs[i],blogs[best],exists)){
                best=i;
            }
        }
        used[best]=1;
        for(int x:blogs[best]){
            if(!exists.count(x)){
                ans.push_back(x);
                exists.insert(x);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
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
