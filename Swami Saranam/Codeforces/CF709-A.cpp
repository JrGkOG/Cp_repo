#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    int x,b,d;
    cin>>x>>b>>d;
    int sum=0;
    int counter=0;
    for(int i=0;i<x;i++){
        int num;
        cin>>num;
        if(num<=b){
            sum+=num;
        }
        if(sum>d){
            counter++;
            sum=0;
        }
    }
    cout<<counter<<"\n";
    return 0;
}