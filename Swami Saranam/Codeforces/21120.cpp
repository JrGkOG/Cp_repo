#include <bits/stdc++.h>
using namespace std;
#define fast() \
ios_base::sync_with_stdio(false); \
cin.tie(NULL);
#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
ll a[n]; \
f(i, n) cin >> a[i]
#define iv(v, n) \
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
    cin >> t;
    while(t--){
        int a, x, y;
        cin >> a >> x >> y;
        if (x > y) {
            swap(x, y);
        }
        
        bool canWin = false;
        for (int b = 1; b <= 100; b++) {
            if (b == a) continue; 
            int bobDistX = abs(b - x);
            int bobDistY = abs(b - y);
            int aliceDistX = abs(a - x);
            int aliceDistY = abs(a - y);
            if (bobDistX < aliceDistX && bobDistY < aliceDistY) {
                canWin = true;
                break;
            }
        }
        
        if (canWin) {
            yes;
        } else {
            no;
        }
    }
}

int main(){
    fast();
    func();
    return 0;
}