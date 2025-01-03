#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

int main(){
    fast();
    int t;
    int n;
    cin>>t>>n;
    string ans;
    string c=to_string(n);
    if(t==1 && n==10){
        cout<<-1<<endl;
        return 0;
    }
    if(n==10){
        ans+="1";
        t=t-1;
        while(t--){
            ans+="0";
        }
    }
    else{
       while(t--){
            ans+=c;
        }
    }
    cout<<ans;
}