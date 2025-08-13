#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define iv(v, n) vector<ll> v(n); for (int i = 0; i < n; i++) cin >> v[i]

vector<vector<pair<int, int>>> graph;
vector<ll> color;
ll totalSum = 0;

void dfs(int node, int parent) {
    for (auto &edge : graph[node]) {
        int neighbor = edge.first;
        int wt = edge.second;
        if (neighbor == parent) continue;
        if (color[node] != color[neighbor]) {
            totalSum += wt;
        }
        dfs(neighbor, node);
    }
}

void solve() {
    ll n, q;
    cin >> n >> q;
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}