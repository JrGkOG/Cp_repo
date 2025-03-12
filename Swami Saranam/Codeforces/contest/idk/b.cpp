#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
        for(ll i=0;i<x;i++){
                cin>>nums[i];
        }
        if(x==1){
            cout<<nums[0]<<endl;
        }
        else{
            sort(nums.begin(),nums.end());
            int curr=nums[0]+nums[1]-1;
            for(int i=2;i<x;i++){
                curr=curr+nums[i]-1;
            }
            cout<<curr<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}