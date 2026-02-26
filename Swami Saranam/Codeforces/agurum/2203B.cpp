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
int firstKeep(int first,vector<int>&rest){
    int budget=9-first;
    if(budget<0)return 0;
    int kept=1;
    for(int d:rest){
        if(budget>=d){
            budget-=d;
            kept++;
        }
        else break;
    }
    return kept;
}
int firstChange(vector<int>&rest){
    int budget=8;
    int kept=0;
    for(int d:rest){
        if(budget>=d){
            budget-=d;
            kept++;
        }
        else break;
    }
    return kept;
}
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    int total=0;
    for(char c:s)total+=c-'0';
    if(total<=9){
        cout<<0<<endl;
        return;
    }
    vector<int>rest;
    for(int i=1;i<n;i++)rest.push_back(s[i]-'0');
    sort(rest.begin(),rest.end());
    int first=s[0]-'0';
    int kept1=firstKeep(first,rest);
    int kept2=firstChange(rest);
    int best=max(kept1,kept2);
    cout<<n-best<<endl;
}

signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}