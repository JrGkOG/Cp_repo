#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

int main(){
    fast();
    ll siz, t;
    cin >> siz >> t;
    ll mid = siz / 2;
    
    if (siz % 2 == 0) {
        if (t > mid) {
            t = t - mid;
            cout << 2 + (t - 1) * 2 << "\n";
        } else {
            cout << 1 + (t - 1) * 2 << "\n";
        }
    } else {
        mid = (siz + 1) / 2;  // Corrected for odd sizes
        if (t > mid) {
            t = t - mid;
            cout << 2 + (t - 1) * 2 << "\n";
        } else {
            cout << 1 + (t - 1) * 2 << "\n";
        }
    }
    return 0;
}
