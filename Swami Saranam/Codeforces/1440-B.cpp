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
        int n,k;
        cin>>n>>k;
        vector<int>nums(n*k);
        for(int i=0;i<n*k;i++){
            cin>>nums[i];
        }
        int sum=0;
        int sub=0;
        if(n==2) sub=n-1;
        else sub=n-2;
        int init=nums.size()-1-(sub);
        for(int i=init;i>=0;i-=sub+1){
            if(k==0) break;
            sum+=nums[i];
            k--;
        }
        cout<<sum<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}