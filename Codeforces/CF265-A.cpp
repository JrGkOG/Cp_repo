#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    int l1=s1.size();
    int l2=s2.size();
    int i=0;
    int j=0;
    int ans=0;
    while(i<l2 && j<l1){
        if(s1[j]==s2[i]){
            i++;
            j++;
            ans=j;
        }
        else{
            i++;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}