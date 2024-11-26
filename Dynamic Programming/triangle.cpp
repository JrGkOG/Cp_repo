#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // done by me dindt see striver good that u have done it 
    // space optimization
    int f(int row, int index, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (row == 0 && index == 0) return triangle[0][0]; 
        if (index < 0 || index >= triangle[row].size()) return INT_MAX;
        if (dp[row][index] != -1) return dp[row][index]; 

        int up = f(row - 1, index, triangle, dp);
        int upLeft = f(row - 1, index - 1, triangle, dp);
        return dp[row][index] = triangle[row][index] + min(up, upLeft);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        // int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // int mini = INT_MAX;
        // for (int i = 0; i < triangle[n - 1].size(); i++) {
        //     mini = min(mini, f(n - 1, i, triangle, dp));
        // }
        // return mini;
        int n=triangle.size();
        vector<int>dp=triangle[n-1];
        for(int row=n-2;row>=0;row--){
            for(int col=0;col<=row;col++){
                dp[col]=triangle[row][col]+min(dp[col],dp[col+1]);
            }
        }
        return dp[0];
    }
};

