#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

int main(){
    fast();
    ll siz,t;
    cin>>siz>>t;
    vector<ll>nums;
    for(ll i=1;i<=siz;i+=2){
        nums.push_back(i);
    }
    for(ll i=2;i<=siz;i+=2){
        nums.push_back(i);
    }
    cout<<nums[t-1]<<endl;
}