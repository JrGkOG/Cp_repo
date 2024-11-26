#include <bits/stdc++.h>

using namespace std;

// house robber problem with constratint that ki the first house and the last house are connected which is the houses are in ciruclar arrangement 

class Solution {
public:
    int soln(vector<int>&nums){
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if((i-2)>=0){
                take+=prev2;
            }
            int notTake=prev;
            int curr=max(take,notTake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>temp1,temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=nums.size()-1){
                temp2.push_back(nums[i]);
            }
        }
        return max(soln(temp1),soln((temp2)));
    }
};