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
        ll first = -1 ;
        ll last = -1;
        for(int i=0;i<x;i++){
            if(first==-1 && (nums[i]%2)!=nums[0]%2){
                first=i;
            }
            else if(nums[i]%2 != nums[x-1]%2){
                last=i;
            }
        }
        if((nums[0]+ nums[x-1])%2){
            cout<<min(first,(x-last-1))<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}