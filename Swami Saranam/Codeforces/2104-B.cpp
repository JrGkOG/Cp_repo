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
        ll n;
        cin>>n;
        vector<ll>nums(n);
        vector<ll>pre1(n);
        vector<ll>pre2(n);
        ll currMaxi=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>nums[i];
            currMaxi=max(nums[i],currMaxi);
            pre1[i]=currMaxi;
        }
        ll prev=0;
        for(int i=n-1;i>=0;i--){
            pre2[i]=prev+nums[i];
            prev=pre2[i];
        }
        cout<<currMaxi<<" ";
        for(int i=n-1;i>=1;i--){
            cout<<pre1[i-1]+pre2[i]<<" "; 
        }
        cout<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}