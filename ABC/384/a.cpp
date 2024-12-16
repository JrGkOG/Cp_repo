#include <bits/stdc++.h>
using namespace std;
int main(){
    int number;
    char a,b;
    string s;
    cin>>number>>a>>b;
    cin>>s;
    for(int i=0;i<number;i++){
        if(s[i]!=a){
            s[i]=b;
        }
    }
    cout<<s<<endl;
    return 0;
}