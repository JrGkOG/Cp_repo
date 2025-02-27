#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   
ll mv(ll x,char c){
    return c=='L' ? x-1 : x+1;
}
void func(){
    int t;
    cin>>t;
    while(t--){
        ll n,x,k;
        cin>>n>>x>>k;
        string s;
        cin>>s;
        ll tim =0;
        for(char c:s){
            ++tim;
            x=mv(x,c);
            if(x==0){
                break;
            }
        }
        if(x!=0){
            cout<<0<<endl;
        }
        else{
            ll ans=1;
            ll ctime=0;
            for(char c:s){
                ++ctime;
                x=mv(x,c);
                if(x==0){
                    break;
                }
            }
            if(x==0){
                ans+=(k-tim)/ctime;
            }
            cout<<ans<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}