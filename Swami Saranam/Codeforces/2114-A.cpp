#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

bool isPerfectSquare(long long x)
{
    if (x > 0) {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
void func(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int x= stoi(s);
        if(int(sqrt(x))* int(sqrt(x))==x){
            cout<<"0 "<<int(sqrt(x))<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}