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
        ll n,k;
        cin>>n>>k;
        vector<int>nums1(n);
        vector<int>nums2(n);
        for(int i=0;i<n;i++) cin>>nums1[i];
        for(int i=0;i<n;i++) cin>>nums2[i];
        vector<int>nums;
        for(int i=0;i<n;i++) {
            nums.push_back(min(nums1[i],nums2[i]));
        }
        sort(nums.begin(),nums.end());
        ll sum=accumulate(nums.begin(),nums.begin()+n-k+1,0LL);
        cout<<accumulate(nums1.begin(),nums1.end(),0LL)+accumulate(nums2.begin(),nums2.end(),0LL) -sum+1<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}