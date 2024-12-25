#include <iostream>
#include <vector>
using namespace std;

bool isDivisibleBy3(long long n, int d) {
    // Check if the sum of digits (d * n!) is divisible by 3
    return (d * n) % 3 == 0;
}

bool isDivisibleBy5(int d) {
    return d == 5;  // Divisible by 5 if d is 5
}

bool isDivisibleBy7(long long n) {
    return n >= 7;  // n! is divisible by 7 if n >= 7
}

bool isDivisibleBy9(long long n, int d) {
    // Check if the sum of digits (d * n!) is divisible by 9
    return (d * n) % 9 == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        int d;
        cin >> n >> d;

        vector<int> result;
        result.push_back(1); // Always divisible by 1
        
        if (isDivisibleBy3(n, d)) {
            result.push_back(3);
        }
        if (isDivisibleBy5(d)) {
            result.push_back(5);
        }
        if (isDivisibleBy7(n)) {
            result.push_back(7);
        }
        if (isDivisibleBy9(n, d)) {
            result.push_back(9);
        }

        // Print the result
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
