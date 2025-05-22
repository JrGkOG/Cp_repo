#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

ll add (ll y){
    cout<<"add "<<y<<endl;
    ll r;
    cin>>r;
    return r;
}
ll mul(ll y){
    cout<<"mul "<<y<<endl;
    ll r ; cin>>r;
    return r;
} 
ll div(ll y){
    cout<<"div "<<y<<endl;
    ll r; cin>>r;
    return r;
}
ll dig(){
    cout<<"digit"<<endl;
    ll r; cin>>r;
    return r;
}
ll done (){
    cout<<"!"<<endl;
    ll r; cin>>r;
    if(r==-1) exit(0);
    return r;
}
void func(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        mul(9);
        dig();
        dig();
        add(n-9);
        done();
    }
}
int main(){
    fast();
    func();
    return 0;
}