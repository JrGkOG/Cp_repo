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
    while (t--) {
        int x;
        cin >> x;
        while (true) {
            if (x == 0) {
                cout << "YES\n";
                break;
            } else if (x < 33) {
                cout << "NO\n";
                break;
            } else {
                string s = to_string(x);
                string new_s;
                bool removed = false;
                for (size_t i = 0; i < s.size(); i++) {
                    if (i < s.size() - 1 && s[i] == '3' && s[i + 1] == '3') {
                        i++; 
                        removed = true;
                    } else {
                        new_s += s[i];
                    }
                }
                if (!removed) {
                    x -= 33;
                } else {
                    x = new_s.empty() ? 0 : stoi(new_s);
                }
            }
        }
    }
    return 0;
}
