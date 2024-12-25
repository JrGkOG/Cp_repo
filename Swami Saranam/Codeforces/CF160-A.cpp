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
    vector<int>nums;
    int total=0;
    for(int i=0;i<t;i++){
        int number;
        cin>>number;
        nums.push_back(number);
        total+=number;
    }
    sort(nums.begin(),nums.end());
    int sum=0;
    int counter=0;
    for(int i=nums.size()-1;i>=0;i--){
        sum+=nums[i];
        total-=nums[i];
        counter++;
        if(sum>total){
            cout<<counter<<endl;
            return 0;
        }
    }
    cout<<counter<<endl;
}