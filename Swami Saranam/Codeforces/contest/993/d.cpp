#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    int t;
    cin>>t;
    while(t--){
        int t2;
        cin>>t2;
        vector<int>there(t2);
        vector<int>notThere(t2);
        iota(notThere.begin(),notThere.end(),1);
        for(int i=0;i<t2;i++){
            cin>>there[i];
            notThere.erase(notThere.begin()+there[i]-1);
        }
        vector<int>ans(t2,-1);
        for(int i=0;i<t2;i++){
            if(ans[i]==there[i]){
                ans[i]=notThere[i];
                cout<<ans[i]<<" ";
            }
            else{
                ans[i]=there[i];
                cout<<ans[i]<<" ";
            }
        }
    }
    return 0;
}