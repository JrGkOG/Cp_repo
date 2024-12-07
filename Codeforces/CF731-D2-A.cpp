#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    char prev = 'a'; 
    for (int i = 0; i < s.size(); i++) {
        int clockwise = abs(s[i] - prev);
        int counterclockwise = 26 - clockwise;
        ans += min(clockwise, counterclockwise);
        prev = s[i];
    }
    cout << ans << endl;
    return 0;
}
