#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<floor((pow(n,2))/4)+1<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}