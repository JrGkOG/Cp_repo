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
        int n,x;
        cin>>n>>x;
        vector<int> nums(n); // fix here
        int totSum=0;
        int c=0;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>nums[i];
            totSum+=nums[i];
            c+=ceil((double)nums[i]/x);
        }
        maxi=c;
        mini=c;
        int i=n-1;
        while(i>=1){
            int num1=nums[i];
            int num2=nums[i-1];
            c-=ceil((double)num1/x); // fix here
            c-=ceil((double)num2/x); // fix here
            c+=ceil((double)(num1+num2)/x); // fix here
            maxi=max(maxi,c);
            mini=min(mini,c);
            i--;
        }
        cout<<mini<<" "<<maxi<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}
