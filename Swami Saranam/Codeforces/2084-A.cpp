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
        ll x;
        cin>>x;
        if(x==1) cout<<-1<<endl;
        else{
            if(x%2==0) cout<<-1<<endl;
            else{
                cout<<x<<" ";
                for(int i=1;i<x;i++){
                    cout<<i<<" ";
                }
                cout<<endl;
            }
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}