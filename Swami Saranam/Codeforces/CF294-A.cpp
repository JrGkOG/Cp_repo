#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; 
    cin >> n; // Number of wires
    vector<int> birds(n + 2, 0); 

    for (int i = 1; i <= n; i++) {
        cin >> birds[i]; 
    }

    int shots;
    cin >> shots; 

    for (int i = 0; i < shots; i++) {
        int wire, bird;
        cin >> wire >> bird; 
        if (wire > 1) {
            birds[wire - 1] += bird - 1; 
        }
        if (wire < n) {
            birds[wire + 1] += birds[wire] - bird; 
        }
        birds[wire] = 0; 
    }

    for (int i = 1; i <= n; i++) {
        cout << birds[i] << "\n"; 
    }
    return 0;
}
