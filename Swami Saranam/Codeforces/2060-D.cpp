#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    ll t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        vector<ll>nums(x);
        for(ll i=0;i<x;i++){
            ll number;
            cin>>number;
            nums[i]=number;
        }
        ll prev= nums[nums.size()-1];
        ll i = nums.size()-2;
        bool flag = false;
        while(i>=0 && flag == false){
            if(nums[i]>prev){
                if(i-1>=0){
                    ll mini1=min(nums[i],prev);
                    ll mini2=min(nums[i],nums[i-1]);
                    if(nums[i]-mini1 <= prev-mini1){
                        prev-=mini1;
                        nums[i]-=mini1;
                        prev=nums[i];
                        i--;
                        continue;
                    }
                    else if(nums[i]-mini2 <= prev){
                        nums[i]-=mini2;
                        nums[i-1]-=mini2;
                        prev=nums[i];
                        i--;
                        continue;
                    }
                    else{
                        flag=true;
                    }
                }
                else{
                    ll mini=min(nums[0],nums[1]);
                    if(nums[0]-mini < nums[1]-mini){
                        i--;
                        continue;
                    }else{
                        flag=true;
                    }
                }
            }
            else{
                prev=nums[i];
                i--;
            }
        }
        if(flag==true){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}