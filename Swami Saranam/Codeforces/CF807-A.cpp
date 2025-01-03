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
    bool isIncreasing = false;
    bool isRated=false;
    int prev=INT_MAX;
    while(t--){
        int number1,number2;
        cin>>number1>>number2;
        if(number1!=number2){
            isRated=true;
        }
        if(number1>prev){
            isIncreasing=true;
        }
        prev=number1;
    }
    if(isRated){
        cout<<"rated";
        return 0;
    }
    else if(!isRated && isIncreasing==true){
        cout<<"unrated";
        return 0;
    }
    else{
        cout<<"maybe";
        return 0;
    }
    return 0;
}