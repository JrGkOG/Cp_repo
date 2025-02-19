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
    while(t--){
        string s;
        cin>>s;
        bool flag=false;
        int i=0;
        while(i<s.size()-1){
            if(s[i]==s[i+1]){
                flag=true;
                break;
            }
            i++;
        }
        if(flag==true){
            cout<<1<<endl;
        }
        else{
            cout<<s.size()<<endl;
        }
    }
 
}