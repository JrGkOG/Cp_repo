#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n + 1);  // Stores teleporter destinations

    // Create an initial valid sequence
    for (int i = 1; i < n; i++) {
        a[i] = i + 1;  // Move forward
    }
    a[n] = 1;  // Create a cycle

    // Simulate teleportation to track the final positions
    vector<int> position(n + 1);
    for (int i = 1; i <= n; i++) {
        int current = i;
        for (int j = 0; j < k; j++) {
            current = a[current];
        }
        position[i] = current;
    }

    // Construct a valid teleportation array ensuring no self-loops
    for (int i = 1; i <= n; i++) {
        cout << position[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
