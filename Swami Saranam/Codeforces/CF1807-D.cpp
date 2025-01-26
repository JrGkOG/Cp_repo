#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void compute(int size, vector<int>& nums, vector<int>& afterSum, vector<int>& beforeSum) {
    int totalSum = 0;
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
        totalSum += nums[i];
    }
    beforeSum[0] = nums[0];
    for (int i = 1; i < size; i++) {
        beforeSum[i] = beforeSum[i - 1] + nums[i];
    }

    afterSum[size - 1] = nums[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        afterSum[i] = afterSum[i + 1] + nums[i];
    }
}

void compute2(int queries, const vector<int>& afterSum, const vector<int>& beforeSum, int size) {
    for (int i = 0; i < queries; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        int finalSum = 0;
        if (l > 0) {
            finalSum += beforeSum[l - 1];
        }
        if (r + 1 < size) {
            finalSum += afterSum[r + 1];
        }
        finalSum += (r - l + 1) * k;
        if (finalSum % 2 == 0) {
            cout<<"NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        int size, queries;
        cin >> size >> queries;
        vector<int> nums(size);
        vector<int> beforeSum(size);
        vector<int> afterSum(size);
        compute(size, nums, afterSum, beforeSum);
        compute2(queries, afterSum, beforeSum, size);
    }
    return 0;
}
