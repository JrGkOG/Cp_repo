#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    unordered_map<int,int>mp;
    int x,y,z,k;
    cin>>x>>y>>z>>k;
    mp[x]+=1;
    mp[y]+=1;
    mp[z]+=1;
    mp[k]+=1;
    int counter=0;
    for(auto it:mp){
        counter+=it.second-1;
    }
    cout<<counter;
}