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
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='@' && c<D){
            c++;
            s[i]='.';
        }
    }
    cout<<s;
    return 0;
}