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
        for(int i=0;i<x;i++){
            cin>>nums[i];
        }
        if(nums[0]!=0){
            cout<<"2 "<<nums.size()<<endl;
            cout<<"1 "<<2<<endl;
        }
        else{
            
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}