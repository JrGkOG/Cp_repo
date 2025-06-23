#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"
bool canFormSquare(int l1, int b1, int l2, int b2, int l3, int b3)
{
    ll totalArea = (ll)l1 * b1 + (ll)l2 * b2 + (ll)l3 * b3;
    ll side = sqrt(totalArea);
    if (side * side != totalArea)
        return false;
    vector<pair<int, int>> rects = {{l1, b1}, {l2, b2}, {l3, b3}};
    sort(rects.begin(), rects.end());
    do
    {
        int a1 = rects[0].first, c1 = rects[0].second;
        int a2 = rects[1].first, c2 = rects[1].second;
        int a3 = rects[2].first, c3 = rects[2].second;
        if (a1 + a2 + a3 == side && c1 == c2 && c2 == c3 && c1 == side)
            return true;
        if (c1 + c2 + c3 == side && a1 == a2 && a2 == a3 && a1 == side)
            return true;
        if (a1 + a2 == side && c1 == c2 && a3 == side && c1 + c3 == side)
            return true;
        if (c1 + c2 == side && a1 == a2 && c3 == side && a1 + a3 == side)
            return true;
        if (a1 + a2 == side && c1 + c3 == side && c2 == c1 && a3 == a1)
            return true;
        if (a1 + a3 == side && c1 + c2 == side && c3 == c1 && a2 == a1)
            return true;
    } while (next_permutation(rects.begin(), rects.end()));
    return false;
}
void func()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        if (canFormSquare(l1, b1, l2, b2, l3, b3))
            yes;
        else
            no;
    }
}
int main()
{
    fast();
    func();
    return 0;
}