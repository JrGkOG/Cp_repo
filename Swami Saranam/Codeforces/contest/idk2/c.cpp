#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
ll gcd(ll a, ll b) { 
    return b == 0 ? a : gcd(b, a % b); 
}
ll lcm(ll a, ll b) { 
    return a / gcd(a, b) * b; 
}
void func() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(n, 0);
        vector<int>res(n, 0);
        bool ans = true;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
            res[i] = (2 * i) % n + 1;
            mp[res[i]]++;
            if (mp[res[i]] > 1){ 
                ans = false;
            }
        }
        if (ans) {
            for (int i = 0; i < n; i++) {
                if (i == 0){
                    cout << res[i];
                }
                else{
                  cout << ' ' << res[i];  
                }
            }
            cout <<endl;
        } else {
            cout <<-1<< "\n";
        }
    }
}

int main() {
    fast();
    func();
    return 0;
}
// -1
// 4 1 3 5 2
// 1 3 2