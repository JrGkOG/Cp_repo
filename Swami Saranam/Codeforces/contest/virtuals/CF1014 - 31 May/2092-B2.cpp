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
        string s1;
        string s2;
        int x;
        cin>>x;
        cin>>s1>>s2;
        int odd=0;
        int even=0;
        for(int i=0;i<x;i++){
            if(s2[i]=='0' && i%2==0){
                even++;
            }
            else if(s2[i]=='0' && i%2!=0){
                odd++;
            }
        }
        bool flag=false;
        for(int i=0;i<x;i++){
            if(s1[i]=='1'){
                if(i%2==0 && odd>=1){
                    odd--;
                }
                else if (i%2!=0 && even >= 1 ) even--;
                else if(i%2==0 && odd==0) flag=true;
                else if(i%2!=0 && even ==0) flag=true;
            }
        }
        if(flag==true) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}