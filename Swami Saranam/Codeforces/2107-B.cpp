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
        ll n,k;
        cin>>n>>k;
        ll total=0;
        vector<int>nums;
        for(ll i=0;i<n;i++){
            ll num;
            cin>>num;
            total+=num;
            nums.push_back(num);
        }
        sort(nums.begin(),nums.end());
        nums[nums.size()-1]--;
        sort(nums.begin(),nums.end());
        if((nums[nums.size()-1] - nums[0])  > k ) cout<<"Jerry"<<endl;
        else{
            if(total%2!=0){
                cout<<"Tom"<<endl;
            }
            else{
                cout<<"Jerry"<<endl;
            }
        }

    }
}
int main(){
    fast();
    func();
    return 0;
}