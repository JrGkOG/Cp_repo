#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long
#define f(i, n) for (int i = 0; i < (n); i++)
#define ia(a, n) \
    int a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<int> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define pb push_back
#define ppb pop_back
#define mp make_pair
const int NUM = 1e6 + 5; 
const int N = 1e7 + 5;  
#define sor(v) sort(v.begin(), v.end())
#define rsor(v) sort(v.begin(), v.end(), greater<>())
#define rev(v) reverse(v.begin(), v.end())
#define DEBUG(x) cerr << #x << ": " << x << '\n'
int mod_pow(int a, int b, int m = MOD) {
    int res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
// muruga enna kapathu
void solve(){
    long long v = 256;
    v = v * v * v * v * v * 2 * 2;
    //v = 0;
    long long w = v + 2;
    long long n, m, dum[n][m], x = 0;
    cin >> n >> m;
    cout << n * m << endl;
    for (int i = 0; i < n; i++){
        for (int j = 1; j < m + 1; j++){
            cout << x + j << " ";
        }
        cout << endl;
        x += 1048576;
        /*
        for (int j = 0; j < m; j++){
            if (i % 2 == 0){
                cout << v << " ";
                dum[i][j] = v;
                if (j % 2 == 0){
                    v++;
                }
                else{
                    v+=3;
                }
            }
            else{
                cout << w << " ";
                dum[i][j] = w;
                if (j % 2 == 0){
                    w++;
                }
                else{
                    w+=3;
                }
                if (j == m -1){
                    if (w % 2 == 0){
                        v = w + 8;
                        w = v + 2;
                    }
                    else{
                        v = w + 9;
                        w = v + 2;
                    }
                }
            }
            //cout << endl;
        }
        cout << endl;
        */
    }
    /*
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << dum[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < m - 1; j++){
            cout << (dum[i][j] ^ dum[i][j+1] ^ dum[i+1][j] ^ dum[i+1][j+1]) << " ";
        }
        cout << endl;
    }
    */
}

signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
