#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'similarPair' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. 2D_INTEGER_ARRAY edges
 */
vector<int> dfs(int node, vector<vector<int>>& adj, vector<vector<int>>& dp) {
    if (!dp[node].empty()) return dp[node]; // Return cached result
    vector<int> ans;
    for (int nextNode : adj[node]) {
        ans.push_back(nextNode);
        vector<int> subResult = dfs(nextNode, adj, dp);
        ans.insert(ans.end(), subResult.begin(), subResult.end());
    }

    return dp[node] = ans;
}

int similarPair(int n, int k, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto &edge : edges) {
        int u = edge[0] - 1;
        int v = edge[1] - 1;
        adj[u].push_back(v);
    }

    vector<vector<int>> dp(n, vector<int>()); // DP table
    int finalAns = 0;

    for (int i = 0; i < n; i++) {
        vector<int> reachableNodes = dfs(i, adj, dp);
        for (int node : reachableNodes) {
            if (abs(i - node) <= k) {
                finalAns++;
            }
        }
    }
    cout << finalAns << endl;
    return finalAns;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    vector<vector<int>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        edges[i].resize(2);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    int result = similarPair(n, k, edges);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
