#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    int N,D;
    cin>>N>>D;
    string s;
    cin>>s;
    int c=0;
    int e=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='@'){
            c++;
        }
        else if(s[i]=='.'){
            e++;
        }
    }
    for(int i=0;i<D;i++){
        c--;
        e++;
    }
    cout<<e;
    return 0;
}