#include <bits/stdc++.h>
using namespace std;
int f(int b,int n){
    if(n<b){
        return n;
    }
    return (n%b)+f(b,floor(n/b));
}
int main(){
    int n,b;
    cin>>n>>b;
    cout<<f(b,n);
}   