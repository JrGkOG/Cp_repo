#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    cin>>t;
    while(t--){
        int a1,a2,a4,a5;
        cin>>a1>>a2>>a4>>a5;
        vector<int>nums;
        nums.push_back(a1+a2);
        nums.push_back(a4-a2);
        nums.push_back(a5-a4);
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            int counter=0;
            if(nums[i]==a1+a2){
                counter++;
            }
            if(a4==nums[i]+a2){
                counter++;
            }
            if(a5==nums[i]+a4){
                counter++;
            }
            maxi=max(counter,maxi);
        }
        cout<<maxi<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}