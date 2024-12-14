#include <bits/stdc++.h>
using namespace std;

int main() {
    string binary1, binary2;
    cin >> binary1 >> binary2;
    string result = "";
    for (size_t i = 0; i < binary1.length(); ++i) {
        result += (binary1[i] == binary2[i]) ? '0' : '1';
    }
    cout << result << endl;
    return 0;
}
