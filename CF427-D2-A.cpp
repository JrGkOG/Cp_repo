#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); // Disable synchronization
    cin.tie(0);
    int x;
    cin>>x;
    stack<int>pos;
    long long counter=0;
    for(int i=0;i<x;i++){
        int number;
        cin>>number;
        if(number>=1){
            while(number!=0){
                pos.push(1);
                number--;
            }
        }
        if(number<0){
            if(pos.empty()==true){
                counter++;
            }
            else if(pos.empty()!=true){
                pos.pop();
            }
        }
    }
    cout<<counter;
}