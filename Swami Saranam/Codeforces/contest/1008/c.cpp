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
        vector<ll>nums(x+x);
        for(ll i=0;i<2*x;i++){
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        // 1 2 3 4
        ll finalNum=0;
        for(int i=0;i<nums.size()-1;i++){
            if(i%2==0){
                finalNum+=nums[i];
            }
            else{
                finalNum-=nums[i];
            }
        }
        finalNum+=nums[nums.size()-1];
        for(int i=0;i<nums.size()-1;i++){
            cout<<nums[i]<<" ";
        }
        cout<<finalNum<<" "<<nums[nums.size()-1]<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
} 