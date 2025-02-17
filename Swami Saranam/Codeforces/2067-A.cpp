#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

int main(){
    fast();
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(x==y){
            cout<<"NO"<<endl;;
        }
        else if(y-x==1){
            cout<<"YES"<<endl;
        }
        else if( x>y && (x-y+1)%9 ==0){
            cout<<"YES"<<endl;
        }
        else if(y==1 && x%9==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}