#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    cin>>t;
    while(t--){
        
        ll n,m,p,q;
        cin>>n>>m>>p>>q;
        if(n%p==0){
            if(((n)*q)==m*p) cout<<yes<<endl;
            else{
                cout<<no<<endl;
            }
        }
        else{
            cout<<yes<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}