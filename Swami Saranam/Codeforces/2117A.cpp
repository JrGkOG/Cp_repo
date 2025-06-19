#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define YES "YES"
#define NO "NO"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    cin>>t;
    while(t--){
        int t,x;
        cin>>t>>x;
        int first=-1;
        int last=-1;
        for(int i=0;i<t;i++){
            int num;
            cin>>num;
            if(num==1 && first ==-1)first =i;
            if(num==1 ) last=i;
        }
        if(last - first>=x) cout<<NO<<endl;
        else cout<<YES<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}