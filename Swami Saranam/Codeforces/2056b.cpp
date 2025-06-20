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
    ll n;
    cin>>n;
    vector<string>adj(n);   
    for(int i=0;i<n;i++){
        cin>>adj[i];
    }
    vector<int>ans(n);
    vector<int>l(n,0);
    vector<int>r(n,n-1);
    for(int i=0;i<n;i++){
        int cnt=0;
        for( int j=0; j<n;j++){
            if(l[j]==l[i] && r[j]==r[i] && adj[i][j]=='1'){
                cnt++;
            }
        }
        int pos = r[i]-cnt;
        ans[pos]=i+1;
        for(int j=0;j<n;j++){
            if(l[j]==l[i] && r[j]==r[i] && i!=j){
                if(adj[i][j]=='0'){
                    r[j]=pos-1;
                }
                else{
                    l[j]=pos+1;
                }
            }
        }
        l[i]=r[i]=pos;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    fast();
    int t;
    cin>>t;
    while(t--){
        func();    
    }
    return 0;
}