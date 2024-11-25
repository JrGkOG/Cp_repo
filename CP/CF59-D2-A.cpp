#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int l=0;
    int u=0;
    for(int i=0;i<s.size();i++){
        if(isupper(s[i])){
            u++;
        }
        else{
            l++;
        }
    }
    if(l>=u){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
    else{
        transform(s.begin(),s.end(),s.begin(),::toupper);
    }
    cout<<s;
}