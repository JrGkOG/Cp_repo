#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

int main(){
    fast();
    int siz,t;
    cin>>siz>>t;
    vector<int>nums;
    for(int i=1;i<=siz;i+=2){
        nums.push_back(i);
    }
    for(int i=2;i<=siz;i+=2){
        nums.push_back(i);
    }
    cout<<nums[t-1]<<endl;
}