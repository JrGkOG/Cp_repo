#include <bits/stdc++.h>
using namespace std;

int main()
{
    int best = 0, sum = 0;
    vector<int> array = {-1, 2, 4, -3, 5, 2, -5, -2};
    int n = array.size();

    cout << "Initial values:\n";
    cout << "best = " << best << ", sum = " << sum << "\n\n";

    for (int k = 0; k < n; k++)
    {
        cout << "Processing array[" << k << "] = " << array[k] << "\n";

        // Update sum: Take the maximum of the current element or adding it to the previous sum
        sum = min(array[k], sum + array[k]);
        cout << "Updated sum = " << sum << "\n";

        // Update best: Track the maximum sum found so far
        best = min(best, sum);
        cout << "Updated best = " << best << "\n\n";
    }

    cout << "Final result:\n";
    cout << "Maximum subarray sum = " << best << "\n";

    return 0;
}
