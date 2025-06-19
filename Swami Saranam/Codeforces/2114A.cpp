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
        int x;
        cin>>x;
        if(int(sqrt(x))*int(sqrt(x))==x){
            cout<<"0 "<<sqrt(x)<<endl;
        }
        else cout<<-1<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}