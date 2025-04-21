#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        string s;
        cin>>s;
        int counter=0;
        int p=1;
        for(int i=0;i<x;i++){
            if(s[i]=='>'){
                p=p-1;
                if(p==0) counter++;
            }else{
                p=p+1;
                if(p==0) counter++;
            }
        }
        int curr=1;
        cout<<curr+counter<<" ";
        int prev=curr+counter;
        for(int i=0;i<x;i++){
            if(s[i]=='<'){
                cout<<prev+1;
            }
            else{
                cout<<"asd"<<" ";
            }
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}