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
        ll k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;
        ll maxPortions = 0;
        if (k < min(a, b)) {
            cout << 0 << "\n";
            continue;
        }
        ll temp1 = k;
        ll portions1 = 0;
        if (temp1 >= a) {
            ll count1 = (temp1 - a) / x + 1;
            portions1 += count1;
            temp1 -= count1 * x;
        }
        if (temp1 >= b) {
            ll count2 = (temp1 - b) / y + 1;
            portions1 += count2;
        }
        maxPortions = max(maxPortions, portions1);
        ll temp2 = k;
        ll portions2 = 0;
        if (temp2 >= b) {
            ll count2 = (temp2 - b) / y + 1;
            portions2 += count2;
            temp2 -= count2 * y;
        }
        if (temp2 >= a) {
            ll count1 = (temp2 - a) / x + 1;
            portions2 += count1;
        }
        maxPortions = max(maxPortions, portions2);
        cout << maxPortions << "\n";
    }
}

int main(){
    fast();
    func();
    return 0;
}