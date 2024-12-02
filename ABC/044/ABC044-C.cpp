#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, A;
  cin >> N >> A;
  vector<int> x(N);
  
  // Input the card values and adjust by subtracting A
  for (int i = 0; i < N; i++)
    cin >> x[i], x[i] -= A; // Adjusting by subtracting A

  // DP array, initialized to 0
  ll dp[51][5000];
  memset(dp, 0, sizeof(dp));

  // Base case: There's one way to achieve sum 0 with no cards selected
  dp[0][2500] = 1;

  // DP transitions
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 5000; j++) {
      if (dp[i][j] > 0) {  // If there's a way to achieve sum j
        // Do not select the current card
        dp[i + 1][j] += dp[i][j];

        // Select the current card
        dp[i + 1][j + x[i]] += dp[i][j];
      }
    }
  }

  // The answer is dp[N][2500] (sum 0), subtract 1 to exclude the empty subset
  cout << dp[N][2500] - 1 << endl;
}
