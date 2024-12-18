#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    set<pair<int,int>>st;
    int t;
    cin>>t;
    int counter=1;
    for(int i=0;i<t;i++){
        int number;
        cin>>number;
        st.insert({number,i+1});
    }
    for(auto it:st){
        cout<<it.second<<" ";
    }
    return 0;
}