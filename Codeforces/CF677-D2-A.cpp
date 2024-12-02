#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// bs approch
void calculate(vector<int>nums,int h,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        if(nums[i]>h){
            sum+=2;
        }
        else{
            sum+=1;
        }
    }
    cout<<sum;
}
// good approcah nice 
void calculate2(vector<int> nums, int h, int n) {
    int start = 0, end = n - 1;
    int greater_count = 0;

    // Binary search to find the first element greater than `h`
    while (start <= end) {
        int mid = (start + end) / 2;

        if (nums[mid] > h) {
            // All elements from `mid` to `end` are greater than `h`
            greater_count = n - mid;
            end = mid - 1; // Search left part for first greater element
        } else {
            // Search right part
            start = mid + 1;
        }
    }

    // Total elements less than or equal to `h`
    int less_or_equal_count = n - greater_count;

    // Compute the total sum
    int sum = (less_or_equal_count * 1) + (greater_count * 2);
    cout << sum;
}

int main(){
    int n,h;

    cin>>n>>h;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int heights;
        cin>>heights;
        nums.push_back(heights);
    }
    sort(nums.begin(),nums.end());
    //calculate(nums,h,n);
    calculate2(nums,h,n);
    return 0;
}
