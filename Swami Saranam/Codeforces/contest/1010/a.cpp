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
        int n, m;
        cin >> n >> m;

        vector<string>a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int r = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            int xr = 0;
            for (int j = 0; j < m; j++)
            {
                xr ^= (a[i][j] - '0');
            }
            if (xr == 1)
                r++;
        }
        for (int j = 0; j < m; j++)
        {
            int xc = 0;
            for (int i = 0; i < n; i++)
            {
                xc ^= (a[i][j] - '0');
            }
            if (xc == 1)
                c++;
        }
        cout<<max(r, c)<<endl;
    }
}
int main()
{
    fast();
    func();
    return 0;
}