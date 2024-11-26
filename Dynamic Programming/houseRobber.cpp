#include <bits/stdc++.h>
using namespace std;
// this is the recursive solution using memoization 
class Solution {
public:
    int f(int index,vector<int>nums,vector<int>&dp){
        if(index==0) return nums[index];
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int take=nums[index]+f(index-2,nums,dp);
        int notTake=f(index-1,nums,dp);
        return dp[index]=max(take,notTake);
    }
    int solve(vector<int>nums){
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
            if((i-2)>=0){
                pick=nums[i]+prev2;
            }
            int notPick=0+prev;
            int curr=max(pick,notPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return f(nums.size()-1,nums,dp); 
    }
};