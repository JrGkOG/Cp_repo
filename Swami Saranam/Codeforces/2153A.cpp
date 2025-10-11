#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    set<int>nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.insert(num);
    }
    cout<<nums.size()<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}