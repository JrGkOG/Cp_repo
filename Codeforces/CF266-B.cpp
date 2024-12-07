#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main(){
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='G'){
            int c=0;
            for(int j=i-1;j>=0;j--){
                if(s[j]=='B' && c++<t){
                    s[j]='G';
                    s[i]='B';
                    i=j;
                }
            }
        }
    }
    cout<<s;
}