#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "YES"
#define no "NO"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if((a+b+c)%3!=0) cout<<no<<endl;
        else{
            ll x= (a+b+c)/3;
            if(x>=b) cout<<yes<<endl;
            else cout<<no<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}