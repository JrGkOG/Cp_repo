#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        vector<int>nums(x);
        vector<vector<int>>posi;
        for(int i=0;i<x;i++){
            cin>>nums[i];
            posi[nums[i]].push_back(i);
        }
        for(int i=0;i<x;i++){
            
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}