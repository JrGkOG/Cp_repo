#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; 
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        nums[i] = abs(nums[i]);
    }
    if(nums.size()<=2){
        cout<<"YES"<<endl;
        return;
    }
    int target = nums[0];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] < target) cnt++;
    }

    int medianPos = n/2 + 1;

    if(cnt >= medianPos)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
