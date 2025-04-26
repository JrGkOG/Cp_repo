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
        for(int i=0;i<x;i++){
            cin>>nums[i];
        }
        bool flag=false;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1] && flag==false){
                cout<<"YES"<<endl;
                cout<<i<<" "<<i+1<<" "<<i+2<<endl;
                flag=true;
            }
        }
        if(flag==false) cout<<"NO"<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}