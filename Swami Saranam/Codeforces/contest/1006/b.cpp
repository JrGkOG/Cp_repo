#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
void func(){
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        ll dash=0;
        ll under=0;
        for(ll i=0;i<s.size();i++){
            if(s[i]=='-'){
                dash++;
            }
            else{
                under++;
            }
        }
        ll ans=(dash/2)*(dash- dash/2);
        ans*=under;
        cout<<ans<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}