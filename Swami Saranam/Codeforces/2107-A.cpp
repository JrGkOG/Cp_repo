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
        vector<int>nums(x);
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<x;i++){
            cin>>nums[i];
            maxi=max(nums[i],maxi);
            mini=min(nums[i],mini);
        }
        if(mini==maxi){
            cout<<no<<endl;
        }
        else{
            cout<<yes<<endl;
            for(int i=0;i<x;i++){
                if(maxi==nums[i]) cout<<1<<" ";
                else cout<<2<<" ";
            }
            cout<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}