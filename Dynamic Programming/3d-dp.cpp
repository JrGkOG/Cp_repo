#include <bits/stdc++.h>
using namespace std;
int f(int i,int j1,int j2,int row,int col,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    // so basically over here we are checking if the index is out of bound 
    // if the index is outof bound we are returing a very small number
    if(j1<0 || j2<0 || j1>=col || j2>=col){
        return -1e9;
    }
    // if the final row is being reached we check if the cols are the same if cols are the same we take only one time 
    // if the cols are not the same we take the respective vals
    if(i==row-1){
        if(j1==j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j2]+grid[i][j1];
        }
    }
    // if the thing has already been stored in the dp we just return it

    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
    // over here we are calculating all the 9 possiblietes and getting the maximum value 
    int maxi=INT_MIN;
    for(int di=-1;di<=1;di++){
        for (int dj=-1;dj<=1;dj++){
            int ans=0;
            if(j1==j2){
                ans=grid[i][j1]+f(i+1,j1+di,j2+dj,row,col,grid,dp);
            }
            else{
                ans=grid[i][j1]+f(i+1,j1+di,j2+dj,row,col,grid,dp)+grid[i][j2];
            }
            maxi=max(ans,maxi);
        }
    }
    return dp[i][j1][j2]=maxi;
}
int maxmimumChocolateMemo(int row,int col,vector<vector<int>>grid){
    vector<vector<vector<int>>>dp(row,vector<vector<int>>(col,vector<int>(col,-1)));
    return f(0,0,col-1,row,col,grid,dp);
}
int maximumChocolateTabulation(int row,int col,vector<vector<int>>grid){
    
}
int main(){
    vector<vector<int>> matrix{
        {2, -3, -1, 2},
        {3, -4, 2, -2},
        {-5, 6, -3, -5},
    };
    int row=matrix.size();
    int col=matrix[0].size();
    cout<<maxmimumChocolateMemo(row,col,matrix)<<" ";
    return 0;
}