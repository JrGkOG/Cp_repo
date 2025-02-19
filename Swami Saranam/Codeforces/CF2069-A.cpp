#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

int main(){
    fast();
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        x=x-2;
        vector<int>nums(x+1);
        bool flag=false;
        for(int i=0;i<x;i++) cin>>nums[i];
        int i=2;
        while(i<x && flag ==false){
            if(nums[i]==1 && nums[i-1]==0 && nums[i-2]==1){
                flag=true;
                cout<<"NO"<<endl;
            }
            i=i+1;
        }
        if(flag==false){
            cout<<"YES"<<endl;
        }
    }
}