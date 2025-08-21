#include <bits/stdc++.h>
using namespace std;

#define ll long long 
void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],vector<int>&tin,vector<int>&low,int& time,vector<vector<int>>&bridge){
    vis[node]=1;
    tin[node]=time;
    low[node]=time;
    time++;
    for(auto it:adj[node]){
        if(it==parent) continue;
        if(!vis[it]){
            dfs(it,node,vis,adj,tin,low,time,bridge);
            low[node]=min(low[node],low[it]);
            if(low[it] > tin[node]){
                bridge.push_back({node,it});
            }
        }
        else{
            low[node] = min(low[node], tin[it]);
        }

    }
}
void findBridge(vector<vector<int>>&connections,int n){
    vector<int>adj[n];
    for(auto it:connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int time=1;
    vector<int>vis(n,0);
    vector<int>tin(n);
    vector<int>low(n);
    vector<vector<int>>bridge;
    dfs(0,-1,vis,adj,tin,low,time,bridge);
    for(auto it:bridge){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
}

int main(){
    vector<vector<int>>c={{0, 1}, {1, 2}, {2, 3}};
    int n=4;
    findBridge(c,n);
    return 0;
}
