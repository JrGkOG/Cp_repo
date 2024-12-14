#include <bits/stdc++.h>
using namespace std;

int main() {
    int inputs;
    cin >> inputs;

    bool flag = false; // Alternate flag for odd number handling
    vector<int> ans(inputs);
    int total_sum = 0;

    // First pass: Transform numbers
    for (int i = 0; i < inputs; i++) {
        int num;
        cin >> num;

        if (num % 2 == 0) { // Even number
            ans[i] = num / 2;
        } else { // Odd number
            if (flag) {
                ans[i] = (num > 0 ? (num / 2) + 1 : (num / 2) - 1);
            } else {
                ans[i] = num / 2;
            }
            flag = !flag; // Toggle flag
        }
        total_sum += ans[i];
    }

    // Second pass: Adjust to ensure sum is zero
    if (total_sum != 0) {
        for (int i = 0; i < inputs; i++) {
            if (ans[i] != 0 && abs(total_sum) == 1) { 
                // Adjust one odd number slightly
                ans[i] -= total_sum;
                total_sum = 0;
                break;
            }
        }
    }

    // Output the results
    for (int i = 0; i < inputs; i++) {
        cout << ans[i] << "\n";
    }
    cout << "Sum: " << total_sum << "\n";
    return 0;
}
