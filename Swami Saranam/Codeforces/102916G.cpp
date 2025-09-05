#include <bits/stdc++.h>
using namespace std;

string minimalSubsequence(const string &s,int k){
    string ans="";
    int n=s.size();
    for(int i=0;i<n;i++){
        char c=s[i];
        while(!ans.empty() && ans.back()>c && ans.size()+n-i-1>=k){
            ans.pop_back();
        }
        if(ans.size()<k) ans.push_back(c);
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    string ans=minimalSubsequence(s,k);
    cout<<ans<<endl;
}
