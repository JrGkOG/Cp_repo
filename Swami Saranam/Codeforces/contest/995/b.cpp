#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main() {
    fast();
    int t;
    cin >> t;
    vector<int> ans;

    while (t--) {
        ll n, a, b, c;
        cin >> n >> a >> b >> c;

        ll sum_per_cycle = a + b + c; 
        ll full_cycles = n / sum_per_cycle; 
        ll remaining_distance = n % sum_per_cycle;

        ll days = full_cycles * 3; 
        if (remaining_distance > 0) {
            days++;
            remaining_distance -= a;
        }
        if (remaining_distance > 0) {
            days++;
            remaining_distance -= b;
        }
        if (remaining_distance > 0) {
            days++;
            remaining_distance -= c;
        }

        ans.push_back(days);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
