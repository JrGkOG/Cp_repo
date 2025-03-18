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
        ll n,k;
        cin>>n>>k;
        if (n % 2 == 0)
        {
            cout<<(n + k - 2) / (k - 1)<<endl;
        }
        else
        {
            ll x = n - k;
            if (x <= 0)
            {
                cout<<1<<endl;
            }
            else{
                cout<<1 + (x + k - 2) / (k - 1)<<endl;
            }

        }
    }
}
int main()
{
    fast();
    func();
    return 0;
}