#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

int main(){
    fast();
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>nums(n,-1);
        int number=1;
        int i=k-1;
        while(i<n && i!=0){
            nums[i]=number++;
            i+=k;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==-1){
                nums[i]=number++;
            }
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
}