#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);

void func() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        ll max_val = 0, sum = 0;
        for (int i = 0; i < x; i++) {
            int num;
            cin >> num;
            max_val = max(max_val, (ll)num);
            sum += num;
        }
        ll result = (sum + y - 1) / y;
        cout << max(result, max_val) << '\n';
    }
}

int main() {
    fast();
    func();
    return 0;
}
