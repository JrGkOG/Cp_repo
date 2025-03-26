#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<ll> arr;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void func()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll n, m, count = 0;
        cin >> n >> m;
        arr nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 0; i--)
        {
            ll groupSize = 1, current = nums[i];
            if (current >= m)
            {
                count++;
                continue;
            }
            while (current < m)
            {
                groupSize++;
                i--;
                if (i < 0)
                    break;
                current = groupSize * nums[i];
            }
            if (current >= m)
                count++;
        }
        cout << count << endl;
    }
}
int main()
{
    fast();
    func();
    return 0;
}