#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    string s;
    cin>>s;
    char prev=' ';
    string ans;
    for(int i=0;i<s.size();i++){
        if(s[i]=='.' && prev==' '){
            ans+='0';
            prev=' ';
        }
        else if(s[i]=='.' && prev=='-'){
            ans+='1';
            prev=' ';
        }
        else if(s[i]=='-' && prev=='-'){
            ans+='2';
            prev=' ';
        }
        else{
            prev=s[i];
        }
    }
    cout<<ans<<endl;
}