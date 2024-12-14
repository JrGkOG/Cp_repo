#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    vector<vector<int>>grid(3,vector<int>(3,-1));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>ans(3,vector<int>(3,1));
    int delRow[]={-1,0,1,0,0};
    int delCol[]={0,-1,0,1,0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i][j]%2!=0){
                for(int k=0;k<5;k++){
                    
                    int row=i+delRow[k];
                    int col=j+delCol[k];
                    if(col>=0 && row>=0 && col<3 && row<3){
                        if(ans[row][col]==1){
                            ans[row][col]=0;
                        }
                        else if(ans[row][col]==0){
                            ans[row][col]=1;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){

            if(j==2){
                cout<<ans[i][j]<<"\n";
            }
            else{
                cout<<ans[i][j];
            }

        }
    }
}
