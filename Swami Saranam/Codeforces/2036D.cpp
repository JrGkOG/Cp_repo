#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   
#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"
void func(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        int numLayers = min(n, m) / 2;
        for (int k = 0; k < numLayers; k++) {
            vector<int>vec;
            for (int j = k; j < m - k; j++) {
                vec.push_back(a[k][j] - '0');
            }
            for (int i = k + 1; i < n - k - 1; i++) {
                vec.push_back(a[i][m - k - 1] - '0');
            }
            for (int j = m - k - 1; j >= k; j--) {
                vec.push_back(a[n - k - 1][j] - '0');
            }
            for (int i = n - k - 2; i > k; i--) {
                vec.push_back(a[i][k] - '0');
            }
            int sz = vec.size();
            for (int i = 0; i < sz; i++) {
                string s;
                for (int j = i; j < i + 4; j++) {
                    s += (char)(vec[j % sz] + '0');
                }
                if (s == "1543") ans++;
            }
        }
        cout << ans << '\n';   
    }
}
int main(){
    fast();
    func();
    return 0;
}