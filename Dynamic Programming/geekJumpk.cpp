#include <bits/stdc++.h>

using namespace std;
int minCost(int k,vector<int>&heights){
    vector<int>dp(heights.size(),-1);
    dp[0]=0;
    for(int i=1;i<heights.size();i++){
        int minCost=INT_MAX;
        for(int j=1;j<=k;j++){
            if((i-j)>=0){
                minCost=min(dp[i-j]+abs(heights[i]-heights[i-j]),minCost);
            }
        }
        dp[i]=minCost;
    }
    return dp[heights.size()-1];
}
/* 
    so over here we are creating a dp array whic stores the minimum cost
    we are staring the loop from the first index and we are storing the first index of the dp array to be 0 as the cost to reach the first index is 0;
    then minStep we are initializeing to max and till k we are going behing which ever is minmum we are taking that as the final minstrep 
    and we are assigning that to the dp 
    so finall the dp of the last is returnd as the min for that is hat onll
*/