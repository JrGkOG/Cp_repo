#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(r<0 || c<0 ) return INT_MAX;
        if(r==0 && c==0) return grid[0][0];
        if(dp[r][c]!=-1) return dp[r][c];
        int top=f(r-1,c,grid,dp);
        int left=f(r,c-1,grid,dp);
        return dp[r][c]=grid[r][c]+min(top,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,-1));
        return f(rows-1,cols-1,grid,dp);
    }
};