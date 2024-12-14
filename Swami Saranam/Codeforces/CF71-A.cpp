#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    int number;
    cin>>number;
    vector<string>s;
    for(int i=0;i<number;i++){
        string str;
        cin>>str;
        if(str.size()>10){
            s.push_back(str[0]+to_string(str.size()-2)+str[str.size()-1]);
        }
        else{
            s.push_back(str);
        }
    }
    for(auto it:s){
        cout<<it<<"\n";
    }
    return 0;
}