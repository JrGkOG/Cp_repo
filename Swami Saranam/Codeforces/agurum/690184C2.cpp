// #include <iostream>
// #include <algorithm>

// using namespace std;

// void solve() {
//     long long n, d;
//     cin >> n >> d;

//     long long min_moves = -1;

//     // k is the total number of *2 operations. Max ~60 for 10^18.
//     for (int k = 0; k <= 60; ++k) {
//         long long power_of_2 = (1LL << k);
        
//         if (power_of_2 > n) break;

//         long long rem = n - power_of_2;
        
//         // If the remaining distance can be formed by adding d
//         if (rem % d == 0) {
//             long long X = rem / d;
            
//             // Mask to get the lower k bits
//             long long lower_mask = power_of_2 - 1;
//             long long lower_bits = X & lower_mask;
            
//             // The rest goes to the final coefficient (after all *2 ops)
//             long long upper_bits = X >> k;
            
//             // Total moves = multiplications + +d ops inside the multiplications + +d ops after
//             long long current_moves = k + __builtin_popcountll(lower_bits) + upper_bits;
            
//             if (min_moves == -1 || current_moves < min_moves) {
//                 min_moves = current_moves;
//             }
//         }
//     }

//     if (min_moves != -1) {
//         cout << "YES " << min_moves << "\n";
//     } else {
//         cout << "NO\n";
//     }
// }

// int main() {
//     // Optimize standard I/O operations for speed
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define int long long
#define yes "YES"
#define no "NO"

map<int, int> memo;

int func(int n, int d) {
    if (n == 1) return 0;
    if (n < 1) return -1;
    
    if (memo.count(n)) return memo[n];

    int min_moves = -1;what

    if (n % 2 == 0) {
        int moves_div = func(n / 2, d);
        if (moves_div != -1) {
            min_moves = moves_div + 1;
        }
    }

    if (d > 0) {
        int steps = 0;
        int temp = n;

        if (temp % 2 != 0) {
            int k = (temp % 2 + d - 1) / d;
            temp -= k * d;
            steps += k;
        }

        if (temp > 0) {
            int moves_sub = func(temp, d);
            if (moves_sub != -1) {
                if (min_moves == -1 || moves_sub + steps < min_moves) {
                    min_moves = moves_sub + steps;
                }
            }
        }
    }

    return memo[n] = min_moves;
}

void solve() {
    int n, d;
    cin >> n >> d;
    
    memo.clear();

    if (d == 0) {
        if (n == 1) cout << yes << " 0\n";
        else cout << no << "\n";
        return;
    }

    int ans = func(n, d);
    
    if (ans != -1) cout << yes << " " << ans << "\n";
    else cout << no << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}