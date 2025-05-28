#include <bits/stdc++.h>
using namespace std;
void Solve()
{
    string a;
    cin >> a;
    multiset<int> s;
    for (auto x : a)
        s.insert(x - '0');
    vector<int> ans;
    for (int i = 1; i <= 10; i++)
    {
        auto it = s.lower_bound(10 - i);
        ans.push_back(*it);
        s.erase(it);
    }
    for (auto x : ans)
        cout << x;
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    for (cin >> T; T--;)
        Solve();
    return 0;
}