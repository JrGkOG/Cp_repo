#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main(){
    fast();
    int t=1;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==b && b==c){
            cout<<"YES";
            return 0;
        }
        int sum1=a+b;
        int sum2=a+c;
        int sum3=c+b;
        if(sum1==c || sum2==b|| sum3==a){
            cout<<"YES";
            return 0;
        }
        cout<<"NO";
        return 0;
    }
}