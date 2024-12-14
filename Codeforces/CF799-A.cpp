#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main(){
    int n,t,k,d;
    cin>>n>>t>>k>>d;
    int bakedCakes=0;
    int time=0;
    while(bakedCakes<n){
        time+=t;
        bakedCakes+=k;
    }
    int time2=0;
    bakedCakes=0;
    while(bakedCakes<n){
        time2+=t;
        if(time2>d){
            bakedCakes+=k+k;
        }
        else{
            bakedCakes+=k;
        }
    }
    if(time2<time){
        cout<<"YES";
        return 0;
    }
    else{
        cout<<"NO";
        return 0;
    }
}