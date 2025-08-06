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
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int inf = 1e18;
const int mod = 1e9 + 7;
const int NUM = 1e6 + 5; 
const int N = 1e7 + 5;  
#define DEBUG(x) cerr << #x << ": " << x << '\n'
vector<int> fact, invfact, power, sieve, lp, primes;

int mod_pow(int a, int b, int m = mod) {
    int res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
int mod_inv(int a, int m = mod) {
    return mod_pow(a, m - 2, m);
}
int mod_div(int a, int b, int m = mod) {
    return (a % m * mod_inv(b, m)) % m;
}
void init_factorials(int max_n = NUM) {
    fact.resize(max_n);
    invfact.resize(max_n);
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < max_n; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    invfact[max_n - 1] = mod_inv(fact[max_n - 1]);
    for (int i = max_n - 2; i >= 1; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
}
int combination(int n, int k) {
    if (k > n || k < 0) return 0;
    return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}
void init_powers(int x, int max_n = NUM) {
    power.resize(max_n);
    power[0] = 1;
    for (int i = 1; i < max_n; i++)
        power[i] = (power[i - 1] * x) % mod;
}
void calc_sieve(int max_n = NUM) {
    sieve.assign(max_n + 1, 0);
    for (int i = 2; i <= max_n; ++i) {
        if (!sieve[i]) {
            for (int j = i; j <= max_n; j += i)
                if (!sieve[j]) sieve[j] = i;
        }
    }
}
void linear_sieve(int max_n = N) {
    lp.assign(max_n + 1, 0);
    for (int i = 2; i <= max_n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.pb(i);
        }
        for (int j = 0; j < sz(primes) && primes[j] <= lp[i] && i * primes[j] <= max_n; ++j)
            lp[i * primes[j]] = primes[j];
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    ll n;
    cin>>n;
    iv(v,n);
    ll prev=-1;
    string s;
    ll l=0;
    ll r=n-1;
    while(r>=l){
        bool can_l = (v[l] > prev);
        bool can_r = (v[r] > prev);
        if(can_l && can_r){
            if(v[l] < v[r]){
                s.append("L");
                prev=v[l];
                l++;
            }
            else if(v[r] < v[l]){
                s.append("R");
                prev=v[r];
                r--;
            }
            else{
                string left_path_moves;
                ll temp_prev = prev;
                for (int i = l; i <= r; ++i) {
                    if (v[i] > temp_prev) {
                        left_path_moves += 'L';
                        temp_prev = v[i];
                    } else {
                        break;
                    }
                }
                string right_path_moves;
                temp_prev = prev;
                for (int i = r; i >= l; --i) {
                    if (v[i] > temp_prev) {
                        right_path_moves += 'R';
                        temp_prev = v[i];
                    } else {
                        break;
                    }
                }
                if (left_path_moves.length() > right_path_moves.length()) {
                    s.append(left_path_moves);
                } else {
                    s.append(right_path_moves);
                }
                break;
            }
        }
        else if(can_l){
            s.append("L");
            prev=v[l];
            l++;
        }
        else if(can_r){
            s.append("R");   
            prev=v[r];
            r--;
        }
        else{
            break;
        }
    }
    cout<<s.size()<<endl;
    for(char c :s) cout<<c;
    cout<<endl;
}

signed main() {
    fast();
    int t = 1;
    while (t--) solve();
    return 0;
}
// [10, 11, 12, 13, 13, 10]
// [1 2, 3, 4, 5, 6, 7,8,9
