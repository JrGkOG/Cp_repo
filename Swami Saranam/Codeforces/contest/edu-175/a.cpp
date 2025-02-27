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
        ll n;
        cin>>n;
        if(n==0) {
            cout<<1<<endl;
            continue;
        }
        else{
            cout<<(n / 15) * 3 + min(3LL, (n % 15) + 1)<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}