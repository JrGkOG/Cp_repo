#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "YES"
#define no "NO"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        set<int>set1;
        set<int>set2;
        for(int i=0;i<x;i++) {
            int num;
            cin>>num;
            set1.insert(num);
        }
        for(int i=0;i<x;i++) {
            int num;
            cin>>num;
            set2.insert(num);
        }
        if(set2.size() > 2 || set1.size()> 2) cout<<yes<<endl;
        else if(set2.size() ==2 && set1.size() == 2 ) cout<<yes<<endl;
        else cout<<no<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}