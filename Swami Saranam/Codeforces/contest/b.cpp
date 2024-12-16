#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    int input;
    cin>>input;
    vector<string>array;
    for(int i=0;i<input;i++){
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='p'){
                s[i]='q';
            }
            else if(s[i]=='q'){
                s[i]='p';
            }
        }
        reverse(s.begin(),s.end());
        array.push_back(s);
    }
    for(int i=0;i<array.size();i++){
        cout<<array[i]<<"\n";
    }
    return 0;
}