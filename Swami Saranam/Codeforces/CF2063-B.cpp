#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int sumOfNMinElements(vector<int>& nums, int start, int end, int n) {
    if (start < 0 || end >= nums.size() || start > end || n <= 0) {
        return INT_MAX; // Use INT_MAX so it does not affect min()
    }

    vector<int> subarray(nums.begin() + start, nums.begin() + end + 1);
    sort(subarray.begin(), subarray.end());
    
    int sum = 0;
    for (int i = 0; i < min(n, (int)subarray.size()); i++) {
        sum += subarray[i];
    }
    return sum;
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        int x, l, r;
        cin >> x >> l >> r;
        vector<int> nums(x);
        
        for (int i = 0; i < x; i++) {
            cin >> nums[i];
        }

        int sumMid = 0;
        for (int i = l - 1; i < r; i++) {
            sumMid += nums[i];
        }

        int left = (l > 1) ? sumOfNMinElements(nums, 0, l - 2, r - l + 1) : INT_MAX;
        int right = (r < x) ? sumOfNMinElements(nums, r, x - 1, r - l + 1) : INT_MAX;

        int ans = min({sumMid, left, right});
        cout << ans << endl;
    }
    return 0;
}
q