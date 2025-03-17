#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    cin>>t;
    while(t--){
        ll x,n,m;
        cin>>x>>n>>m;
        ll logi=ceil(log2(x));
        if(n>=logi){
            cout<<0<<" "<<0<<endl;
        }
        else{
            if(n==0 || m==0){
                while(n!=0 && x!=0){
                    x=floor(x/2);
                    n--;
                }
                while(x!=1 && m!=0){
                    m--;
                    x=ceil(x/2);
                }
                cout<<x<<" "<<x<<endl;
            }
            else{
                ll mini=x;
                ll maxi=x;
                while(n!=0 && m!=0 && maxi!=1 && mini!=0){
                    mini=floor(x/2);
                    maxi=ceil(x/2);
                    m--;
                    n--;
                }
                while(n!=0 && mini!=0){
                    mini=floor(x/2);
                    maxi=floor(x/2);
                    n--;
                }
                while(maxi!=1 && m!=0){
                    m--;
                    maxi=ceil(x/2);
                    mini=ceil(x/2);
                }
                cout<<mini<<" "<<maxi<<endl;
            }
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}