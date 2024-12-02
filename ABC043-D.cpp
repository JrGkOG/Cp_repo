#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0 ; i < s.size() ; i++) {
        if (i + 1 < s.size() && s[i] == s[i + 1]) {
            cout << i + 1 << " " << i + 2; 
            return 0;
        }
        if (i + 2 < s.size() && s[i] == s[i + 2]) {
            cout << i + 1 << " " << i + 3; 
            return 0;
        }
    }
    cout << "-1 -1";
    return 0;
}

