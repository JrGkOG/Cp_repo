#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    for (int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;
        if (gcd(a, b) == 1)
        {
            printf("%10d%10d    Good Choice\n", a, b);
        }
        else
        {
            printf("%10d%10d    Bad Choice\n", a, b);
        }
    }
    return 0;
}

