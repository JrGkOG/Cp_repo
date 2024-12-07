#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int inputs;
    cin >> inputs;
    vector<int> arr(inputs);
    unordered_map<int, int> indexMap; 
    for (int i = 0; i < inputs; i++) {
        cin >> arr[i];
        indexMap[arr[i]] = i + 1; 
    }
    int search;
    cin >> search;

    vector<int> sr(search);
    for (int i = 0; i < search; i++) {
        cin >> sr[i];
    }
    ll ans1 = 0, ans2 = 0;
    for (int num : sr) {
        if (indexMap.find(num) != indexMap.end()) {
            int index = indexMap[num];
            ans1 += index;
            ans2 += inputs - index + 1;
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}
