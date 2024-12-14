#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    int inps;
    cin >> inps;
    unordered_map<int, int> mp;
    vector<int>nums;
    for (int i = 0; i < inps; i++) {
        int x, y;
        cin >> x >> y;  
        mp[y]++;
        nums.push_back(x);
    }

    int sum = 0;
    for(auto it:nums){
        if(mp.find(it)!=mp.end()){
            sum+=mp[it];
        }
    }
    cout << sum;
    return 0;
}
