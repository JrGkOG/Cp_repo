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
    int first;
    int second;
    cin>>first;
    set<int>st;
    for(int i=0;i<first;i++){
        int number;
        cin>>number;
        st.insert(number);
    }
    cin>>second;
    for(int i=0;i<second;i++){
        int number;
        cin>>number;
        st.insert(number);
    }
    if(st.size()==t){
        cout<<"I become the guy."<<endl;
        return 0;
    }
    else{
        cout<<"Oh, my keyboard!"<<endl;
        return 0;
    }
    return 0;
}