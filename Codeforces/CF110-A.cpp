#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    ll number;
    cin>>number;
    int count=0;
    while(number!=0){
        int digit=number%10;
        if((digit==4)|| (digit==7)){
            count++;
        }
        number=number/10;
    }
    if(count==4 || count==7){
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
}