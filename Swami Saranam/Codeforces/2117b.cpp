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
        int num;
        cin>>num;
        vector<int>nums(num);
        nums[0]=1;
        nums[num-1]=2;
        int j=3;
        for(int i=1;i<num-1;i++){
            nums[i]=j++;
        }
        for(int i=0;i<num;i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}