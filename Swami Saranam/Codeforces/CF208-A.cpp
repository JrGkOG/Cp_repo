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
    string answer;
    if(s.size()<3){
        cout<<s<<endl;
        return 0;
    }
    bool yes=true;
    while(i<s.size()-3){
        if(s[i] =='W' && s[i+1]=='U' && s[i+2]=='B'){
            i+=3;
            if(!yes){
                answer+=" ";
            }
            yes=true;
        }
        else{
            answer+=s[i];
            i+=1;
            yes=false;
        }
    }
    if(s[i] =='W' && s[i+1]=='U' && s[i+2]=='B'){
        cout<<answer<<endl;
        return 0;
    }
    else{
        while(i<s.size()){
            answer+=s[i];
            i++;
        }
        cout<<answer<<endl;
        return 0;
    }
}