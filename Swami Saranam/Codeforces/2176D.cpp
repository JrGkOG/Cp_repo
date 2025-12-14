#include <bits/stdc++.h>
using namespace std;
int64_t f(int64_t u,int64_t v,vector<int64_t>dp,vector<int>&node2,int64_t vl,int64_t m){
    int64_t c=0;
    if(dp[vl]!=-1){
        c=dp[vl];
    }
    else{
        for(int64_t i=0;i<m;i++){
            if(node2[i]==vl){
                c++;
            }
        }
    }
    if(c==0){
        return 0;
    }
    return dp[vl]=c+f(v,vl,dp,node2,v+vl,m);
}
int main() {
    int64_t t;
    cin>>t;
    while(t--){
        int64_t n,m;
        cin>>n>>m;
        vector<int64_t>v(n);
        int64_t mx=INT_MIN;
        for(int64_t i=0;i<n;i++){
            cin>>v[i];
            mx=max(mx,v[i]);
        }
        vector<vector<int64_t>>adj;
        adj.resize(n+1);
        vector<vector<int>>str(m+1,vector<int>(2,0));
        vector<int>node2;
        for(int64_t i=0;i<m;i++){
            int64_t u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            str[i][0]=u;
            str[i][1]=v;
            node2.push_back(v);
        }
        vector<int64_t>dp(n*mx+1,-1);
        int64_t c=0;
        for(int64_t i=0;i<m;i++){
            int64_t u=str[i][0];
            for(auto it:adj[u]){
              c++;
              int64_t x=f(v[u-1],v[it-1],dp,node2,v[u-1]+v[it-1],m);
              c+=x;
            }
        }
        cout<<c<<endl;;
    }
}