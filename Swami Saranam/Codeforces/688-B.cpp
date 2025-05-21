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
    t=1;
    while(t--){
        string x;
        cin>>x;
        string tempx=x;
        reverse(tempx.begin(),tempx.end());
        x=x+tempx;
        cout<<x<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}