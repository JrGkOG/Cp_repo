#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   
#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"
void func(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        iv(v,n);
        ll y=(2*v[0]-v[1])/(n+1);
        ll x=v[1]-v[0]+y;
        bool flag=false;
        if(y < 0 || x < 0) flag =true;
        f(i,n){
            v[i] -=x*(i+1);
            v[i] -=y*(n-i);
        }
        
        f(i,n){
            if(v[i]!=0) flag=true;
        }
        if(flag) no;
        else yes;
    }
}
int main(){
    fast();
    func();
    return 0;
}