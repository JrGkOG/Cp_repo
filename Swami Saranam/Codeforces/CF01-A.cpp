#include <bits/stdc++.h>
using namespace std;

#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

int main(){
    fast();
    long double x,y,z;
    cin>>x>>y>>z;
    cout<<(ceil(x/z))*(ceil(y/z));
}