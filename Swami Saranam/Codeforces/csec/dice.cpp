#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int mod=1e9+7;
int f(int node,vector<vector<int>>&dp,vector<int>nums,int target){
    if(node<0) return 0;
    if(node==0){
        if(nums[node] <= target) return 1;
        else return 0;
    }
    if(dp[node][target]!=-1) return dp[node][target];
    int no=f(node-1,dp,nums,target);
    int yes=0;
    if(nums[node]<=target){
        yes=1+(f(node-1,dp,nums,target-nums[node]))%mod;
    }
    return dp[node][target]=(yes%mod+no%mod)%mod;
}
void solve(){
    int n;
    cin>>n;
    vector<int>nums={1,2,3,4,5,6};
    vector<vector<int>>dp(nums.size()+1,vector<int>(n+1,-1));
    cout<<f(nums.size()-1,dp,nums,n)<<endl;
}
int main(){
    int t;
    t=1;
    while(t--) solve();
    return 0;
}