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
        ll n;
        cin>>n;
        int cnt2=0,cnt3=0;
        while(n%2==0){
            n/=2;
            ++cnt2;
        }
        while(n%3==0){
            n/=3;
            ++cnt3;
        }
        if(n==1 && cnt2<=cnt3){
            cout<<(cnt3-cnt2+cnt3)<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}