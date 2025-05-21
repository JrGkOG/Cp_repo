#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define yes "Yes"
#define no "No"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef pair<ll, ll> pp;
void func()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, p;
        cin >> n >> p;
        vector<ll> a(n), cost(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n; i++)
            cin >> cost[i];

        ll ans = p, need = n - 1; // you've spread news to one pep
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for (ll i = 0; i < n; i++)
        {
            pq.push({cost[i], a[i]});
        }
        pq.push({p, n - 1});

        while (need > 0 && !pq.empty())
        {
            auto [ithCost, ithpps] = pq.top();
            pq.pop();

            ll cur_need = min(need, ithpps);
            ans += cur_need * ithCost;
            need -= cur_need;
        }

        cout << ans << endl;
    }
}
int main()
{
    fast();
    func();
    return 0;
}