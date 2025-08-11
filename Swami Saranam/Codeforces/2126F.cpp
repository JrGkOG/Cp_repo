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
    // Use 1-based indexing for color to match input, avoids off-by-one errors
    color.assign(n + 1, 0); 
    for (int i = 1; i <= n; i++) cin >> color[i];

    graph.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        ll src, dest, wt;
        cin >> src >> dest >> wt;
        graph[src].push_back({dest, wt});
        graph[dest].push_back({src, wt});
    }

    // --- LOGIC FIXED HERE ---
    for (int i = 0; i < q; i++) {
        ll v, new_c;
        cin >> v >> new_c;
        color[v-1] = new_c; // Repaint the single node for this query

        // Recalculate the entire sum from scratch
        totalSum = 0;
        dfs(1, -1); // Start DFS from node 1 (or any node)

        // Print the answer for THIS query (and fix the double-counting)
        cout << totalSum / 2 << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}