#include <bits/stdc++.h>

using namespace std;

int main(){
    int count5=0;
    int count7=0;
    for(int i=0;i<3;i++){
        int number;
        cin>>number;
        if(number==5){
            count5++;
        }
        else if(number==7){
            count7++;
        }
    }
    if(count7==1 && count5==2){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}