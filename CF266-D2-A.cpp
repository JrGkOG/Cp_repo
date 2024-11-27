#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    char prev=' ';
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]==prev){
            count++;
        }
        else{
            prev=s[i];
        }
    }
    cout<<count;
}