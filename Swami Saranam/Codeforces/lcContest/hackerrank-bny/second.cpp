#include <bits/stdc++.h>
using namespace std;
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int x : h1) sum1 += x;
    for (int x : h2) sum2 += x;
    for (int x : h3) sum3 += x;

    int i = 0, j = 0, k = 0;

    while (true) {
        if (i == (int)h1.size() || j == (int)h2.size() || k == (int)h3.size())
            return 0;
        if (sum1 == sum2 && sum2 == sum3)
            return sum1;
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1[i];
            i++;
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2[j];
            j++;
        } else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= h3[k];
            k++;
        }
    }
}

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> h1(n1), h2(n2), h3(n3);

    for (int i = 0; i < n1; i++) cin >> h1[i];
    for (int i = 0; i < n2; i++) cin >> h2[i];
    for (int i = 0; i < n3; i++) cin >> h3[i];

    cout << equalStacks(h1, h2, h3) << "\n";

    return 0;
}
