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
        string s1;
        string s2;
        int num;
        cin>>num;
        cin>>s1;
        cin>>s2;
        int counter=0;
        for(int i=1;i<num-1;i++){
            if(s1[i]=='.' && s1[i+1]!='x' &&s1[i-1]!='x' && s2[i]=='.' && s2[i+1]=='x' && s2[i-1]=='x'){
                counter++;
            }
        }
        for(int i=1;i<num-1;i++){
            if(s2[i]=='.' && s2[i+1]!='x'&&s2[i-1]!='x' && s1[i]=='.' && s1[i+1]=='x' && s1[i-1]=='x'){
                counter++;
            }
        }   
        cout<<counter<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}