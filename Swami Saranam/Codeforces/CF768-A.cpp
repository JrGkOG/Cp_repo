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
    int maxi=INT_MIN;
    int mini=INT_MAX;
    for(int i=0;i<t;i++){
        int number;
        cin>>number;
        nums.push_back(number);
        if(maxi<number){
            maxi=number;
        }
        if(mini>number){
            mini=number;
        }
    }
    int counter=0;
    for(int i=0;i<t;i++){
        if(nums[i]>mini && nums[i]<maxi){
            counter++;
        }
    }
    cout<<counter<<endl;
}