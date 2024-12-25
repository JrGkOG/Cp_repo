#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> missing_questions(m);
        for (int i = 0; i < m; ++i) {
            cin >> missing_questions[i];
        }

        unordered_set<int> known_questions;
        for (int i = 0; i < k; ++i) {
            int q;
            cin >> q;
            known_questions.insert(q);
        }

        string result;
        for (int i = 0; i < m; ++i) {
            int a_i = missing_questions[i];
            // If the missing question is not known, Monocarp must know all others
            if (known_questions.find(a_i) == known_questions.end()) {
                result += '1'; // Monocarp can pass
            } else {
                result += '0'; // Monocarp cannot pass
            }
        }

        cout << result << '\n';
    }

    return 0;
}