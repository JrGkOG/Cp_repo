#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i,int j,vector<vector<int>>&nums,vector<vector<int>>&dp){
        if(i<0 || j<0 || nums[i][j]==1) return 0;
        if(i ==0 && j==0 ) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int top = f(i-1,j,nums,dp);
        int left=f(i,j-1,nums,dp);
        return dp[i][j]=top+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>&nums) {
        int rows=nums.size();
        int cols=nums[0].size();
        if(nums[0][0]==1 || nums[rows-1][cols-1]==1){
            return 0;
        }
        vector<vector<int>>dp(rows,vector<int>(cols,-1));
        return f(rows-1,cols-1,nums,dp);

    }
};