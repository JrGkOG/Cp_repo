#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    int x,y;
    cin>>x>>y;
    int counter=max(x,y);
    if(counter>6){
        cout<<"0/1";
    }
    if(counter==1){
        cout<<"1/1";
    }
    else if(counter==2){
        cout<<"5/6";
    } 
    else if(counter==3){
        cout<<"2/3";
    }
    else if(counter==4){
        cout<<"1/2";
    }
    else if(counter==5){
        cout<<"1/3";
    }
    else if(counter==6){
        cout<<"1/6";
    } 
    return 0;
}