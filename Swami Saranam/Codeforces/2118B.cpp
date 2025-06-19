#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast() \
ios_base::sync_with_stdio(false); \
 cin.tie(NULL);

void func(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<tuple<int, int, int>> a;
        a.emplace_back(1, 1, n);

        for (int d = 2; d <= n; ++d) {
            int x = n - d + 1;
            int y = x + 1;

            a.emplace_back(d, 1, x);
            if (y <= n) {
                a.emplace_back(d, y, n);
            }
        }

        cout << a.size() << '\n';
        for (auto &[x, y, z] : a) {
            cout << x << " " << y << " " << z << '\n';
        }
    }
}

int main(){
    fast();
    func();
    return 0;
}