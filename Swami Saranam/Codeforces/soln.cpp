#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

pair<int, int> dfs(int u, int p, const vector<vector<int>>& adj) {
    vector<pair<int, int>> child_results;
    bool is_leaf = true;
    for (int v : adj[u]) {
        if (v != p) {
            is_leaf = false;
            child_results.push_back(dfs(v, u, adj));
        }
    }

    if (is_leaf) {
        return {1, 0};
    }

    sort(child_results.rbegin(), child_results.rend());

    int p1_coins = 1;
    int p2_coins = 0;

    for (int i = 0; i < child_results.size(); ++i) {
        if (i % 2 == 0) {
            p2_coins += child_results[i].first;
            p1_coins += child_results[i].second;
        } else {
            p1_coins += child_results[i].first;
            p2_coins += child_results[i].second;
        }
    }

    return {p1_coins, p2_coins};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<int, int> final_score = dfs(1, 0, adj);

    cout << final_score.first << endl;

    return 0;
}
