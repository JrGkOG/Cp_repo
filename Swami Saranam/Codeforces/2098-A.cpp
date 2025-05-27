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
        vector<int>nums(10);
        for(int i=0;i<s.size();i++){
            nums[s[i]-'0']++;
        }

    }
}
int main(){
    fast();
    func();
    return 0;
}