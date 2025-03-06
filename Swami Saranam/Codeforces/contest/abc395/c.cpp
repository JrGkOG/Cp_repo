#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    t=1;
    while(t--){
        ll x;
        cin>>x;
        ll mini=INT_MAX;
        unordered_map<ll,pair<ll,ll>>mp;
        for(int i=0;i<x;i++){
            ll num;
            cin>>num;
            if(mp[num].first>=1){
                mp[num].first++;
                mini=min(mini,abs(i-mp[num].second+1));
            }
            else{
                mp[num].first++;
                mp[num].second=i;
            }
        }
        if(mini==INT_MAX){
            cout<<-1<<endl;
        }
        else{
            cout<<mini<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}