#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main() {
    fast();
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c) {
        cout << "Yes";
        return 0;
    }
    if (a + b == c || a + c == b || b + c == a) {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}
