#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> constructAdj(vector<vector<int>> &edges, int V) {
    vector<vector<vector<int>>> adj(V);
    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    return adj;
}

int bitwise_or_bfs(int V, vector<vector<int>> &edges, int src, int end) {
    vector<vector<vector<int>>> adj = constructAdj(edges, V);
    vector<int> min_or(V, INT_MAX);
    queue<pair<int, int>> q;
    q.push({src, 0});
    min_or[src] = 0;

    while (!q.empty()) {
        auto [u, cost] = q.front();
        q.pop();
        for (auto &x : adj[u]) {
            int v = x[0];
            int wt = x[1];
            int newCost = cost | wt;
            if (min_or[v] > newCost) {
                min_or[v] = newCost;
                q.push({v, newCost});
            }
        }
    }
    return min_or[end] == INT_MAX ? -1 : min_or[end];
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u - 1, v - 1, wt});
    }
    int a, b;
    cin >> a >> b;
    cout << bitwise_or_bfs(n, edges, a - 1, b - 1) << endl;
}

int main() {
    int t = 1;
    while (t--) solve();
    return 0;
}
