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
        ll m;cin>>m;
        vector<ll>nums(m);
        for(int i=0;i<m;i++) {
            cin>>nums[i];
        }
        ll tomake=nums[0];
        ll counter=0;
        ll counter2=0;
        ll totalNeeded= ceil(m/2);
        for(int i=1;i<m;i++){
            if(nums[i]>=tomake) {
                counter++;
            }
            else if(nums[i]*(-1) >=tomake)counter++;
            else{
                counter2++;
            }
        }
        if(totalNeeded<=counter)cout<<yes<<endl;
        else cout<<no<<endl;


    }
}
int main(){
    fast();
    func();
    return 0;
}