#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast() \
ios_base::sync_with_stdio(false); \
cin.tie(NULL);

void func(){
    int t;
    cin >> t;
    while(t--){
        ll w,h,a,b;
        ll x1,y1,x2,y2;
        cin>>w>>h>>a>>b;
        cin>>x1>>y1>>x2>>y2;
        ll rx1 = ((x1 % a) + a) % a;
        ll rx2 = ((x2 % a) + a) % a;
        ll ry1 = ((y1 % b) + b) % b;
        ll ry2 = ((y2 % b) + b) % b;
        bool vert_ok = (rx1 == rx2) && (x1 != x2);
        bool horiz_ok = (ry1 == ry2) && (y1 != y2);
        if (vert_ok || horiz_ok) {
            cout << yes << "\n";
        } else {
            cout << no << "\n";
        }
    }
}

int main(){
    fast();
    func();
    return 0;
}