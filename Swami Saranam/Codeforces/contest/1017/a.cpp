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
        int n,k,p;
        cin>>n>>k>>p;
        if(k<0 && n*(-p) > k ){
            cout<<-1<<endl;
        }
        else if(k>0 && n*p < k ){
            cout<<-1<<endl;
        }
        else if(k==0){
            cout<<0<<endl;
        }
        else {
            int counter=0;
            while(k!=0 && n!=0){
                counter+=k/p;
                n-=k/p;
                k=k%p;
                if(k > -p && k<p && n>=1){
                    counter+=1;
                    k=0;
                }
            }
            cout<<counter<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}
