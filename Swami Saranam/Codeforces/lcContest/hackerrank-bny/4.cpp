#include <bits/stdc++.h>
using namespace std;

int cookies(int k, vector<int>& A) {
    priority_queue<int, vector<int>, greater<int>> minHeap(A.begin(), A.end());
    int operations = 0;

    while (minHeap.size() > 1 && minHeap.top() < k) {
        int least = minHeap.top(); minHeap.pop();
        int secondLeast = minHeap.top(); minHeap.pop();
        int newSweetness = least + 2 * secondLeast;
        minHeap.push(newSweetness);
        operations++;
    }

    if (!minHeap.empty() && minHeap.top() >= k) return operations;
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    cout << cookies(k, A) << endl;
    return 0;
}
