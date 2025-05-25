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
        vector<ll>nums(x);
        for(int i=0;i<x;i++){
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        ll mini=nums[0];
        ll maxi=nums[x-1];
        if((mini + maxi)%2==0) cout<<0<<endl;
        else{
            if(mini%2==0){
                c
            }
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}