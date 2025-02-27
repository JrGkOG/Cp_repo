#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
void func(){
    lli t;
    cin>>t;
    while(t--){
        lli arr,x;
        cin>>arr>>x;
        vector<lli>nums(arr,0);
        for(lli i=0;i<arr;i++){
            if((i&x)!=i){
                break;
            }
            else{
                nums[i]=i;
            }
        }
        lli ans=0;
        for(lli i=0;i<arr;i++){
            ans|=i;
        }
        if(ans!=x){
            nums[arr-1]=x;
        }
        for(lli i=0;i<arr;i++){
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