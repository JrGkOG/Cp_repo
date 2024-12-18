#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    vector<int>coords;
    vector<pair<int,int>>ans;
    for(int i=0;i<t;i++){
        int num;
        cin>>num;
        coords.push_back(num);
    }
    for(int i=0;i<t;i++){
        int mini=0;
        int maxi=0;
        if(i==0){
            mini=abs(coords[i]-coords[i+1]);
            maxi=abs(coords[i]-coords[t-1]);
            ans.push_back({mini,maxi});
        }
        else if(i==t-1){
            mini=abs(coords[t-1]-coords[t-2]);
            maxi=abs(coords[i]-coords[0]);
            ans.push_back({mini,maxi});
        }
        else{
            mini=min(abs(coords[i]-coords[i-1]),abs(coords[i]-coords[i+1]));
            maxi=max(abs(coords[i]-coords[0]),abs(coords[i]-coords[t-1]));
            ans.push_back({mini,maxi});
        }
    }
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}