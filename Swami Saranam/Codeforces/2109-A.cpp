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
        ll x;
        cin>>x;
        vector<ll>nums(x);
        for(int i=0;i<x;i++) cin>>nums[i];
        bool flag=false;
        ll cnt=0;
        for(int i=0;i<x;i++){
            if(nums[i]==1)cnt++;
        }
        if(cnt==x) flag=true;
        for(int i=1;i<x;i++){
            if(nums[i]== nums[i-1] && nums[i]==0) flag=true;
        }
        if(flag) cout<<yes<<endl; 
        else cout<<no<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}