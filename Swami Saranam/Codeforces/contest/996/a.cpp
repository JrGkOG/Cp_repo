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
        int n,a,b;
        cin>>n>>a>>b;
        if(abs(a-b)==1){
            cout<<"NO"<<endl;
        }
        else{
            if(a>b){
                while(a!=b){
                    a--;
                    if(a==b){
                        cout<<"NO"<<endl;
                        break;
                    }
                    else if(b+1==a){
                        cout<<"YES"<<endl;
                        break;
                    }
                    b++;
                }
            }
            else if(a<b){
                while(a!=b){
                    a++;
                    if(a==b){
                        cout<<"NO"<<endl;
                        break;
                    }
                    else if(b-1==a){
                        cout<<"YES"<<endl;
                        break;
                    }
                    else{
                        b--;
                    }
                }
            }
        }

    }
}
int main(){
    fast();
    func();
    return 0;
}