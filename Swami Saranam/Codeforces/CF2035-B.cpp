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
        int x;
        cin>>x;
        if(x==1 || x==3) cout<<-1<<"\n";
        else{
            if(x%2==0){
                int i=1;
                while(i<=x){
                    if(i<x-1) cout<<"3";
                    else cout<<"6";
                    i++;
                }
                cout<<endl;
            }
            else{
                // 6366
                int i=1;
                x=x-4;
                while(i<=x){
                    cout<<"3";
                    i++;
                }
                cout<<"6366\n";
            }
        }
    }
    return 0;
}