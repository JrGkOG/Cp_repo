#include <bits/stdc++.h>
using namespace std;

int maxWins(vector<int> a, vector<int> b) {
    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int wins = 0;
    int j = 0;
    int n = a.size();
    
    // Use two pointers to find maximum wins
    for (int i = 0; i < n; i++) {
        // Find the smallest dealer card that this player card can beat
        while (j < n && b[j] >= a[i]) {
            j++;
        }
        
        if (j < n) {
            wins++;
            j++;
        }
    }
    
    return wins;
}

int solve() {
    int n;
    cin >> n;
    
    vector<int> player(n), dealer(n);
    
    for (int i = 0; i < n; i++) {
        cin >> player[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> dealer[i];
    }
    
    // Calculate base wins without any swap
    int maxResult = maxWins(player, dealer);
    
    // Try all possible swaps
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Swap cards at positions i and j
            swap(player[i], player[j]);
            
            // Calculate wins with this swap
            int currentWins = maxWins(player, dealer);
            maxResult = max(maxResult, currentWins);
            
            // Swap back to original configuration
            swap(player[i], player[j]);
        }
    }
    
    return maxResult;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        cout << solve() << "\n";
    }
    
    return 0;
}