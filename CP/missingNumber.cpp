#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long totalSum = n * (n + 1) / 2;
    long long sum = 0;
    for (long long i = 0; i < n - 1; i++) {
        long long num;
        cin >> num;
        sum += num;
    }
    long long missingNumber = totalSum - sum;
    cout << missingNumber << endl;
    return 0;
}
