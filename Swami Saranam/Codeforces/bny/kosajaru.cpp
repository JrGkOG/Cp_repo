#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void dfs(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]) dfs(it,vis,st,adj);
    }
    st.push(node);
}
void dfs2(int node,vector<int>&vis,vector<int>& nodes,vector<int>adj[]){
    vis[node]=1;
    nodes.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]) dfs2(it,vis,nodes,adj);
    }
}
void kosajaru(vector<vector<int>>&edgeList,int n,vector<vector<int>>&ans){
    vector<int>adj[n];
    vector<int>adj2[n];
    for(auto it:edgeList){
        adj[it[0]].push_back(it[1]);
        adj2[it[1]].push_back(it[0]);
    }
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i,vis,st,adj);
    }
    vector<int>vis2(n,0);
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis2[node]){
            vector<int>temp;
            dfs2(node,vis2,temp,adj2);
            ans.push_back(temp);
        }
    }
    for(auto it:ans){
        for(auto x:it) cout<<x<<" ";
        cout<<"\n";
    }
}
int main(){
    vector<vector<int>>edgeList={{0,2},{2,1},{1,0},{0,3},{3,4}};
    int n=5;
    vector<vector<int>>vec;
    kosajaru(edgeList,n,vec);
}
 