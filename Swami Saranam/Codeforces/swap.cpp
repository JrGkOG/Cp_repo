#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int left=0;
    int right= s.size()-1;
    vector<int>nums{1,23,1,2,4,2,4,5,23,1};
    while(left < right){
        swap(s[left],s[right]);
        left++;
        right--;
    }
    cout<<s<<endl;
    sort(nums.begin(),nums.end());
    for(auto it:nums){
        cout<<it<<" ";
    }
    cout<<endl;
}