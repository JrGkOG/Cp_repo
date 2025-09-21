#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long 


void solve(){
    ll n;cin>>n;
    map<ll,ll> freq;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        freq[x]++;
    }
    priority_queue<pair<ll,ll>> pq;
    for (auto &it : freq) {
        pq.push({it.second, it.first});
    }
    ll alice=0,bob=0;
    bool flag=0;
    while(!pq.empty()){
        auto topi=pq.top();
        pq.pop();
        int mod=(topi.second+1)/2;
        if(!flag){
            alice+=mod*topi.first;
            bob+=topi.first*(topi.second-mod);
            if(topi.second & 1){
                flag=1;
            }
        }
        else{
            int mod=(topi.second+1)/2;
            bob+=mod*topi.first;
            alice+=topi.first*(topi.second-mod);
            if(topi.second & 1){
                flag=0;
            }
        }
    }
    cout<<alice<<" "<<bob<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}