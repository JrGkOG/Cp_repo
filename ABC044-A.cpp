#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,K,X,Y;
    cin>>N>>K>>X>>Y;
    int sum=0;
    for(int i=0;i<N;i++){
        if(i+1<=K){
            sum+=X;
        }
        else{
            sum+=Y;
        }
    }
    cout<<sum;
}