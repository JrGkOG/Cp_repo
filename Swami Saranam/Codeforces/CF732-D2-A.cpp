#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    int cost,k;
    cin>>cost>>k;
    bool foundMini=false;
    int minVal=INT_MAX;
    int i=1;
    while(foundMini==false){
        if(((cost*i)%10==0) || ((cost*i)-k)%10==0){
            cout<<i;
            return 0;
        }
        else{
            i=i+1;
        }
    }
    return 0;
}