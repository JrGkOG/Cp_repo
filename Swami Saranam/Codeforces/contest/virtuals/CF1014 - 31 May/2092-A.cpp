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
        int maxi=0;
        int mini=INT_MAX;
        for(int i=0;i<x;i++){
            int num;
            cin>>num;
            maxi=max(maxi,num);
            mini=min(mini,num);
        }
        cout<<maxi-mini<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}