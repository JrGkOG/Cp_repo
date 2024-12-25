#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

int main(){
    fast();
    char c;
    cin>>c;
    string s;
    string ans;
    cin>>s;
    if(c=='R'){
        string p="qwertyuiopasdfghjkl;zxcvbnm,./";
        for(int i=0;i<s.size();i++){
            ans+=p[p.find(s[i])-1];
        }
    }
    else{
        string p="qwertyuiopasdfghjkl;zxcvbnm,./";
        for(int i=0;i<s.size();i++){
            ans+=p[p.find(s[i])+1];
        }
    }
    cout<<ans<<endl;
}