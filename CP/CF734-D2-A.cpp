#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    string s;
    cin>>s;
    int d=0;
    int a=0;
    for(int i=0;i<s.size();i++){
        if (s[i]=='D'){
            d++;
        }
        else{
            a++;
        }
    }
    if(d>a){
        cout<<"Danik";
    }
    else if(a>d){
        cout<<"Anton";
    }
    else{
        cout<<"Friendship";
    }
    return 0;
}