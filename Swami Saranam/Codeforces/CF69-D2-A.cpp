#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    int n;
    cin>>n;
    vector<int>nums(3,0);
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        nums[0]+=x;
        nums[1]+=y;
        nums[2]+=z;
    }
    for(int i=0;i<3;i++){
        if(nums[i]!=0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;   
}