#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void func()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<long long>());
        long long maxCost = 0;
        for (int i = 0; i < k; i++)
        {
            maxCost += a[i];
        }
        maxCost += a[k];
        cout << maxCost << endl;
    }
}

int main()
{
    fast();
    func();
    return 0;
}