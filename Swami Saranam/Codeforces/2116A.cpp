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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int miniG=min(a,c);
        int miniF=min(b,d);
        if(miniG >= miniF){
            cout<<"Gellyfish"<<endl;
        }
        else if(miniF > miniG){
            cout<<"Flower"<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}