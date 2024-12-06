#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll binPow(ll x,ll y,ll mod){
    if(y==0){
        return 1;
    }
    ll res=binPow(x,y/2,mod);
    if(y%2){
        return (res*res*x)%mod;
    }
    else{
        return (res*res)%mod;
    }
}
int main(){
    int inputs;
    cin>>inputs;
    for(int i=0;i<inputs+1;i++){
        if(i==inputs){
            int dump;
            cin>>dump;
        }
        else{
            long long x,y,n,z;
            cin>>x>>y>>n;
            z=binPow(x,y,n);
            cout<<z<<"\n";
        }

    }
}
