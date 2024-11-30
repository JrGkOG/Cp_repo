#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,L;cin>>N>>L;
    vector<string>S(N);
    for(auto &s:S){
        cin>>s;
    }
    sort(S.begin(),S.end());
    for(auto it:S){
        cout<<it;
    }
    return 0;
}