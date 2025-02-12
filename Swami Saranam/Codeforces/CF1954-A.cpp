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
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int max_color=(n+m-1)/m;
        if(max_color+k>=n){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}