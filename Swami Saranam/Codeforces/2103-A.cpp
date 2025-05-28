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
        ll x;
        cin>>x;
        set<int>nums;
        for(int i=0;i<x;i++){
            int num;
            cin>>num;
            nums.insert(num);
        }
        cout<<nums.size()<<endl;


        // 7 4 3 2
        // 24 
    }
}
int main(){
    fast();
    func();
    return 0;
}