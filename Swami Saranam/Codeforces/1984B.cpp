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
    ll n; 
    cin >> n;
    n = n - n % 10 + (n % 10 + 1) % 10;
    while (n > 9) {
        if (n % 10 == 0) {
        cout << "NO\n";
        return;
        }
        n /= 10;
    }
    cout << (n == 1 ? "YES\n" : "NO\n");
}
int main(){
    fast();
    int t;
    cin>>t;
    while(t--) func();
    return 0;
}