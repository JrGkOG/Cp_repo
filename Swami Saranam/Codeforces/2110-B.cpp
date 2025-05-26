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
        string s;
        cin>>s;
        vector<int>nums(s.size());
        ll prev=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                nums[i]=prev+1;
                prev=nums[i];
            }
            else{
                nums[i]=prev-1;
                prev=nums[i];
            }
        }
        bool flag=false;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==0) flag=true;
        }
        if(flag==true) cout<<yes<<endl;
        else cout<<no<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}