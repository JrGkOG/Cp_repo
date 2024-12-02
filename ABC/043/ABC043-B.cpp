#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    string s;
    cin>>s;
    stack<char>stk;
    string ans;
    for(int i=0;i<s.size();i++){
        if(s[i]=='B'){  
            if(stk.empty()!=true){
                stk.pop();
            }
        }
        else{
            stk.push(s[i]);
        }
    }
    while(!stk.empty()){
        ans+=stk.top();
        stk.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}