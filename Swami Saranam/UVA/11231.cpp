#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> ans;
    bool flag = true;
    
    while (flag) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0) {
            flag = false;
            break;
        }
        
        if (x < 8 || y < 8) {
            ans.push_back(0);
            continue;
        }
        int counter = 0;
        for (int row = 8; row <= x; ++row) {
            for (int col = 8; col <= y; ++col) {
                int color = (row + col) % 2; 
                if (color != z) {
                    counter++;
                }
            }
        }
        ans.push_back(counter);
    }

    // Print results
    for (auto it : ans) {
        cout << it << endl;
    }

    return 0;
}
