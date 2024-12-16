#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main(){
    int n,r;
    cin>>n>>r;
    for(int i=0;i<n;i++){
        int di,ai;
        cin>>di>>ai;
        if(di==1){
            if(r>=1600 && r<=2799){
                r+=ai;
            }
        }
        else if(di==2){
            if(r>=1200 && r<=2399){
                r+=ai;
            }
        }
    }
    cout<<r<<endl;
    return 0;
}