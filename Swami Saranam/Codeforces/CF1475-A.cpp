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
        ll number;
        cin>>number;
        if(number%2!=0 && number>1){
            cout<<"YES\n";
        }
        else{
            while(number%2==0){
                number=number/2;
            }
            if(number==1){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }
    }
    return 0;
}