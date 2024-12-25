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
    string s;
    cin>>s;
    transform(s.begin(),s.end(),s.begin(),::toupper);
    vector<bool>vec(26,false);
    for(int i=0;i<s.size();i++){
        int number = s[i]-'A';
        vec[number]=true;
    }
    for(int i=0;i<vec.size();i++){
        if(vec[i]==false){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}