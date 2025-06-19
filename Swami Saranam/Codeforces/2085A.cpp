// 54ba1503-a626-482f-9b36-d638ddbf0762
#include <bits/stdc++.h>
using namespace std;

bool isUniversal(const string& s)                 // r < rev(r) ?
{
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        char l = s[i];
        char r = s[n - 1 - i];
        if (l != r) return l < r;                 // first difference
    }
    return false;                                 // identical – not smaller
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  cin >> T;
    while (T--) {
        int n, k;       cin >> n >> k;
        string s;       cin >> s;

        if (isUniversal(s)) {                     // already good
            cout << "YES\n";
            continue;
        }

        if (k == 0) {                             // no operation allowed
            cout << "NO\n";
            continue;
        }

        bool manyKinds = false;
        for (char c : s)
            if (c != s[0]) { manyKinds = true; break; }

        cout << (manyKinds ? "YES\n" : "NO\n");
    }
    return 0;
}