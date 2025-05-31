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
        ll odd=0;
        ll even=0;
        ll x;
        cin>>x;
        vector<ll>nums(x);
        vector<ll>odd1(x);
        vector<ll>even1(x);
        ll maxi=0;
        for(ll i=0;i<x;i++){
            cin>>nums[i];
            if(nums[i]%2==0) {
                even+=1;
                even1.push_back(nums[i]);
            }
            else {
                odd+=1;
                odd1.push_back(nums[i]);
            }
            maxi=max(nums[i],maxi);
        }
        if(even == x || odd == x) cout<<maxi<<endl;
        else{
            sort(even1.begin(),even1.end());
            sort(odd1.begin(),odd1.end());
            for(int i=0;i<odd1.size()-1;i++){
                if(odd1[i] >=2){
                    even1[0]+=odd1[i]-1;
                }
            }
            ll total=0;
            for(int i=0;i<even1.size();i++){
                total+=even1[i];
            }
            total+=odd1[odd1.size()-1];
            cout<<total<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}