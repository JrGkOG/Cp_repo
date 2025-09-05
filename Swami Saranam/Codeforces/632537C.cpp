#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm> // For std::min and std::max

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, A, B;
    std::cin >> N >> A >> B;

    std::vector<double> dp(N + 1);
    dp[N] = 0.0; // Base case: If we have N stickers, 0 more packets are needed.

    // Calculate P, the number of possible stickers in a packet
    double P = static_cast<double>(B - A + 1);

    // window_sum will store the sum of dp[j] for j in the range [i_start, i_end]
    // where i_start = i + A and i_end = min(N, i + B)
    double window_sum = 0.0;

    // Initialize window_sum for dp[N-1]
    // The range for dp[N-1] is [N-1+A, min(N, N-1+B)]
    for (int j = (N - 1) + A; j <= std::min(N, (N - 1) + B); ++j) {
        window_sum += dp[j]; // These dp[j] values are either dp[N] (0.0) or haven't been computed yet.
                             // However, for j >= N-A, dp[j] will be 1.0. Let's handle that properly.
    }
    
    // Iterate from N-1 down to 0
    for (int i = N - 1; i >= 0; --i) {
        // If i + A >= N, all future packets will complete the album.
        // So dp[i] = 1.0. The sum of dp[N] terms is 0.
        if (i + A >= N) {
            dp[i] = 1.0;
        } else {
            // dp[i] = 1 + (sum of dp[j] from i+A to min(N, i+B)) / P
            // The window_sum should be containing the correct values from dp[i+A] to dp[min(N, i+B)]
            dp[i] = 1.0 + (window_sum / P);
        }

        // Update window_sum for the next iteration (i-1)
        // For dp[i-1], the window is [i-1+A, min(N, i-1+B)]
        // Compared to dp[i]'s window [i+A, min(N, i+B)]:

        // 1. Remove the term dp[i+A] from the sum IF i+A is within the window AND i+A < N
        //    (we only remove if the term was actually added and not 0)
        if (i + A < N) { // If i+A is a valid index for dp
             window_sum -= dp[i + A];
        } else { // if i+A >= N, then dp[i+A] would be dp[N] which is 0, so no change.
            // However, it could be that i+A-1 was N, which should be fine.
        }

        // 2. Add the term dp[min(N, i-1+B)] to the sum.
        //    This term is the new rightmost element for dp[i-1].
        //    We only add if i-1+B is a valid index to consider adding.
        if (i - 1 + B >= 0) { // Ensure the index is non-negative
            window_sum += dp[std::min(N, i - 1 + B)];
        }
    }

    std::cout << std::fixed << std::setprecision(10) << dp[N] << std::endl;

    return 0;
}