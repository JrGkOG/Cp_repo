#include <bits/stdc++.h>
using namespace std;
#define ll long long 
bool findXForSum(vector<ll>& dp, ll S, ll Sum) {
    ll target = Sum - S;  
    ll left = 0, right = dp.size() - 1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;

        if (dp[mid] == target) {
            return true;  
        } else if (dp[mid] < target) {
            left = mid + 1;  
        } else {
            right = mid - 1;  
        }
    }

    return false;  
}
int main() {
    ll n, s;
    cin >> n >> s;
    vector<ll> nums(n);
    vector<ll>dp(n,0);
    ll prev=0;
    for (ll i = 0; i < n; i++) {
        cin >> nums[i];
        dp[i]=nums[i]+prev;
        prev+=nums[i];
    }
    ll sum=0;
    while(true){
        if(sum > s-dp[n-1]){
            sum+=dp[n-1];
        }
        else{
            if(findXForSum(dp,s,sum)){
                cout<<"YES"<<endl;
                return 0;
            }
            else{
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    return 0;
}
