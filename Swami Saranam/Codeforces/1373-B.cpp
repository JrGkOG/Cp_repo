#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int o=0,z=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')o++;
            else z++;
        }
        if(o ==0 || z==0 ) cout<<"NET"<<endl;
        else if(min(o,z)%2!=0) cout<<"NET"<<endl;
        else cout<<"DA"<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}