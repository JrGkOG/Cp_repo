#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

int main(){
    fast();
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        if(x%2!=0){
            cout<<"NO"<<endl;
        }
        else{
            map<ll,ll>mp;
            ll itemp=x; 
            ll maxi=INT_MIN;
            while(x!=0){
                ll num;
                cin>>num;
                mp[num]+=1;
                maxi=max(maxi,num);
            }
            for(auto it:mp){
                if(maxi-it.first> it.second){
                    
                }
            }
        }
    }
}