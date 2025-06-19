#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void func()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;

        if (x == 0) cout<<0<<endl;
        else{
            int bits = 0;
            int temp = x;
            while (temp > 0)
            {
                bits++;
                temp >>= 1;
            }
            cout<<2 * bits + 1<<endl;
        }
        
    }
}
int main()
{
    fast();
    func();
    return 0;
}