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
        int n , m , k;
        cin>>n>>m>>k;
        vector<int>nums(n);
        for(int i=n;i>m;i--){
            cout<<i<<" ";
        }
        for(int i=1;i<=m;i++){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}