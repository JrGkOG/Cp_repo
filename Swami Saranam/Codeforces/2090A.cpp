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
        int x, y, a;
        cin >> x >> y >> a;
        if (a % (x + y) < x) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}