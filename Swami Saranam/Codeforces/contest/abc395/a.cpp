#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    t=1;
    while(t--){
        int n;
        cin>>n;
        int prev=INT_MIN;
        bool flag=false;
        while(n-- && flag==false){
            int num;
            cin>>num;
            if(num<=prev){
                flag=true;
            }
            else{
                prev=num;
            }
        }
        if(flag==true){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}