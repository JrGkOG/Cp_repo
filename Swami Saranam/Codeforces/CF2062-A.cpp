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
        int one = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                one++;
            }
        }
        cout<<one<<endl;
    }
}