#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n)     \
    ll a[n];         \
    f(i, n) cin >> a[i]
#define iv(v, n)       \
    vector<ll> v(n);   \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

void func() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        if (m < n || m > n * (n + 1) / 2) {
            cout << "-1\n";
            continue;
        }
        ll s_min = n;
        ll s_max = (n == 1) ? 1 : n + (n - 1) * n / 2;
        if (m < s_min || m > s_max) {
            cout << "-1\n";
            continue;
        }
        int root = -1;
        for (int cur_root = 1; cur_root <= n; ++cur_root) {
            ll rem = m - cur_root;
            ll min_rem = n - 1;
            ll max_rem = (ll)(cur_root - 1) * cur_root / 2 + (ll)(n - cur_root) * cur_root;
            if (rem >= min_rem && rem <= max_rem) {
                root = cur_root;
                break;
            }
        }
        if (root == -1) {
            cout << "-1\n";
            continue;
        }
        cout << root << nline;
        vector<pair<int, int>> edges;
        vector<pair<ll, int>> gains;
        for (int i = 1; i <= n; ++i) {
            if (i != root) {
                gains.push_back({(ll)min(i, root) - 1, i});
            }
        }
        sort(gains.begin(), gains.end(), greater<pair<ll, int>>());
        ll extra = (m - root) - (n - 1);
        vector<bool> toRoot(n + 1, false);
        for (auto &p : gains) {
            ll gain = p.first;
            int node = p.second;
            if (extra >= gain) {
                toRoot[node] = true;
                extra -= gain;
            }
        }
        if (extra != 0) {
            cout << "-1\n";
            continue;
        }
        vector<bool> used(n + 1, false);
        used[root] = true;
        int pivot = -1;
        if (n > 1) {
            if (root != 1) {
                pivot = 1;
            } else {
                for (int i = 2; i <= n; ++i) {
                    if (i != root) {
                        pivot = i;
                        break;
                    }
                }
            }
        }
        if (n > 1 && pivot != -1 && pivot != root) {
            edges.push_back({root, pivot});
            used[pivot] = true;
        }
        if (n == 1) {
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            if (i == root) continue;
            if (toRoot[i]) {
                if (!used[i]) {
                    edges.push_back({root, i});
                    used[i] = true;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (i == root || used[i]) continue;
            edges.push_back({pivot, i});
            used[i] = true;
        }
        for (auto &e : edges) {
            cout << e.first << " " << e.second << nline;
        }
    }
}

int main() {
    fast();
    func();
    return 0;
}
