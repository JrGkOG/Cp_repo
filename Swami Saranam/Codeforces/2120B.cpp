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
        int n,s;
        cin>>n>>s;
        int cnt=0;
        for(int i=0;i<n;i++){
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            if(a==b){
                if((c-d)%s==0){
                    cnt++;
                }
            }else{
                if((c+d)%s == 0){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}