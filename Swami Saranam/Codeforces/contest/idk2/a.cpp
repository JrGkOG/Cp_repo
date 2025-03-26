#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        vector<int>nums(x);
        for(int i=0;i<x;i++){
            cin>>nums[i];
        }
        int zer=3;
        int one=1;
        int thre=1;
        int two=2;
        int fiv=1;
        int i=0;
        bool flag=false;
        while(i<nums.size() && flag!=true){
            int num=nums[i];
            i++;
            if(num==0){
                zer--;
                if(zer<=0 && one<=0 && thre<=0 && two<=0 && fiv<=0){
                    cout<<i<<endl;
                    flag=true;
                }
            }
            else if(num==5){
                fiv--;
                if(zer<=0 && one<=0 && thre<=0 && two<=0 && fiv<=0){
                    cout<<i<<endl;
                    flag=true;
                }
            }
            else if(num==1){
                one--;
                if(zer<=0 && one<=0 && thre<=0 && two<=0 && fiv<=0){
                    cout<<i<<endl;
                    flag=true;
                }
            }
            else if(num==2){
                two--;
                if(zer<=0 && one<=0 && thre<=0 && two<=0 && fiv<=0){
                    cout<<i<<endl;
                    flag=true;
                }
            }
            else if(num==3){
                thre--;
                if(zer<=0 && one<=0 && thre<=0 && two<=0 && fiv<=0){
                    cout<<i<<endl;
                    flag=true;
                }
            }
        }
        if(flag==false){
            cout<<0<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}