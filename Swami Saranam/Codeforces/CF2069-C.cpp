#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

ll mod=998244353;
ll add(ll x,ll y){
    x+=y;
    return x%mod;
}
void func(){
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        vector<ll>dp(4,0);
        dp[0]=1;
        while(x--){
            ll p;
            cin>>p;
            if(p==2) dp[p]=add(dp[p],dp[p]);
            dp[p]=add(dp[p],dp[p-1]);
        }
        cout<<dp[3]<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}