#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    unordered_map<char,int>mp;
    for(auto it:s){
        mp[it]+=1;
    }
    for(auto it:mp){
        if(it.second%2!=0){
            cout<<"No";
            return 0;
        }
        
    }
    cout<<"Yes";
    return 0;
}