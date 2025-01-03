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
    string s1=" ";
    string s2=" ";
    int counts1=0;
    int counts2=0;
    while(t--){
        string s;
        cin>>s;
        if(s!=s1 && s!=s2){
            if(s1==" "){
                s1=s;
                counts1+=1;
            }
            if(s2==" "){
                s2=s;
                counts2+=1;
            }
        }
        else if(s==s1){
            counts1+=1;
        }
        else if(s==s2){
            counts2+=2;
        }
    }
    if(counts1>counts2){
        cout<<s1<<endl;
        return 0;
    }
    else{
        cout<<s2<<endl;
        return 0;
    }
}