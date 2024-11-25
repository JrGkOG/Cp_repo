#include <bits/stdc++.h>
using namespace std;

void algo(long long first){
    while(first!=1 && first>=0 ){
        cout<<first<<" ";
        if(first%2==0){
            first=first/2;
        }
        else{
            first=(first*3)+1;
        }
    }
}
int main(){
    long long first;
    cin>>first;
    algo(first);
    cout<<1;
}