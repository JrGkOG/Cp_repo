#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    int number1,number2;
    cin>>number1>>number2;
    vector<int>nums={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,47};
    for(int i=0;i<nums.size()-1;i++){
        if(number1==nums[i]){
            if(number2==nums[i+1]){
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}