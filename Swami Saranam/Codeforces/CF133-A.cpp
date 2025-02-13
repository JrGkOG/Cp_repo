#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

int main(){
    fast();
    string s;
    cin>>s;
    int i=0;
    bool flag=false;
    while(i<s.size() && flag ==false){
        if(s[i]=='H' || s[i]=='Q' || s[i]=='9'){
            flag=true;
        }
        i++;
    }
    if(flag){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}