#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // dp[last_val][min_tail]
    // min_tail = n + 1: The subsequence is strictly increasing.
    // min_tail <= n: The minimum tail of any decreasing pair.
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 2, 0));

    long long total_good_subsequences = 1; // For the empty subsequence

    for (int val : a) {
        // Use a map to temporarily store the counts for new subsequences ending in 'val'.
        // This prevents using updates from the current iteration to calculate other updates in the same iteration.
        map<int, long long> ways_ending_in_val;

        // Case 1: The subsequence {val} itself. It's increasing.
        ways_ending_in_val[n + 1] = 1;

        // Case 2: Extend all previously found good subsequences.
        for (int last = 1; last <= n; ++last) {
            // 2a: Extend subsequences that were strictly increasing. These can always be extended.
            if (dp[last][n + 1] > 0) {
                long long count = dp[last][n + 1];
                int new_min_tail;
                if (val < last) { // The first descent (last > val) is formed.
                    new_min_tail = val;
                } else { // The subsequence remains increasing at its end.
                    new_min_tail = n + 1;
                }
                ways_ending_in_val[new_min_tail] = (ways_ending_in_val[new_min_tail] + count) % MOD;
            }

            // 2b: Extend subsequences that already had a descent.
            for (int min_tail = 1; min_tail <= n; ++min_tail) {
                if (dp[last][min_tail] > 0) {
                    // THE CORRECT CRUCIAL CONDITION:
                    if (val >= min_tail) {
                        long long count = dp[last][min_tail];
                        int new_min_tail;
                        if (val < last) { // Forms another descent, update min_tail if necessary.
                            new_min_tail = min(min_tail, val);
                        } else { // The minimum tail does not change.
                            new_min_tail = min_tail;
                        }
                        ways_ending_in_val[new_min_tail] = (ways_ending_in_val[new_min_tail] + count) % MOD;
                    }
                }
            }
        }

        // Add the counts for all newly formed subsequences to the DP table and the total.
        for (auto const& [mt, cnt] : ways_ending_in_val) {
            dp[val][mt] = (dp[val][mt] + cnt) % MOD;
            total_good_subsequences = (total_good_subsequences + cnt) % MOD;
        }
    }

    cout << total_good_subsequences << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}