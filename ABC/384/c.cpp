#include <bits/stdc++.h>
using namespace std;

int calculateWeight(const string& subset, const unordered_map<char, int>& weights) {
    int sum = 0;
    for (char ch : subset) {
        sum += weights.at(ch);
    }
    return sum;
}

void generateSubsets(const string& elements, vector<string>& subsets) {
    int n = elements.size();
    int totalSubsets = 1 << n;
    for (int mask = 1; mask < totalSubsets; ++mask) {
        string subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset += elements[i];
            }
        }
        subsets.push_back(subset);
    }
}

int main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    unordered_map<char, int> weights = {{'A', A}, {'B', B}, {'C', C}, {'D', D}, {'E', E}};
    string elements = "ABCDE";
    vector<string> subsets;
    generateSubsets(elements, subsets);

    auto comparator = [](const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comparator)> pq(comparator);

    for (const string& subset : subsets) {
        int weight = calculateWeight(subset, weights);
        pq.push({weight, subset});
    }

    while (!pq.empty()) {
        cout << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}
