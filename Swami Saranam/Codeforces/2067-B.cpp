#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   
#define Yes cout<<"YES"<<endl;
#define No cout<<"NO"<<endl;
void func(){
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        vector<int>nums(x+1,0);
        for(int i=0;i<x;i++){
            int num;
            cin>>num;
            nums[num]++;
        }
        for(int i=0;i<x;i++){
            if(nums[i]>2){
                nums[i+1]+=nums[i]-2;
                nums[i]=2;
            }
        }
        bool flag=true;
        for(int i=0;i<x;i++){
            if(nums[i]%2!=0){
                No;
                flag=false;
                break;
            }
        }
        if(flag==true){
            Yes;
        }
    }
}

int main(){
    fast();
    func();
    return 0;
}