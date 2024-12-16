#include <bits/stdc++.h>
#define ll  long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >> t; 
    while (t--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        ll count = 0;
        for (ll x = l1; x <= r1; ++x) {
            ll y = x;
            while (y <= r2) {
                if (y >= l2) { 
                    count++;
                }
                if (y > r2 / k) {
                    break;
                }
                y *= k;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
