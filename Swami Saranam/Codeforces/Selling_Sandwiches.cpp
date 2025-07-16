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
    int n;
    cin >> n;
    vector<ll> a(n);
    f(i, n) cin >> a[i];

    sort(all(a), greater<ll>());

    vector<ll> prefixA(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixA[i + 1] = prefixA[i] + a[i];
    }

    vector<ll> s_bonus(2 * n + 2, 0);
    for (int i = 1; i <= 2 * n + 1; ++i) {
        s_bonus[i] = s_bonus[i - 1] + (i - 1);
    }

    auto get_f = [&](ll k, ll j) {
        if (j == 0) return 0LL;
        ll start_bonus_idx = 2 * j - k;
        if (start_bonus_idx < 0) return -INF;
        return prefixA[j] + s_bonus[j] - s_bonus[start_bonus_idx];
    };

    vector<ll> ans(2 * n + 1, 0);

    function<void(int, int, int, int)> compute =
        [&](int k_start, int k_end, int j_start, int j_end) {
        if (k_start > k_end) {
            return;
        }

        int k_mid = k_start + (k_end - k_start) / 2;
        int j_low_limit = (k_mid + 1) / 2;
        int j_high_limit = min(k_mid, n);

        int opt_j = -1;
        ll max_val = -1;

        int search_j_start = max(j_start, j_low_limit);
        int search_j_end = min(j_end, j_high_limit);

        if (search_j_start <= search_j_end) {
            for (int j = search_j_start; j <= search_j_end; ++j) {
                ll val = get_f(k_mid, j);
                if (val > max_val) {
                    max_val = val;
                    opt_j = j;
                }
            }
        }
        ans[k_mid] = max_val;

        if (opt_j != -1) {
            compute(k_start, k_mid - 1, j_start, opt_j);
            compute(k_mid + 1, k_end, opt_j, j_end);
        } else {
            compute(k_start, k_mid - 1, j_start, j_end);
            compute(k_mid + 1, k_end, j_start, j_end);
        }
    };

    compute(1, 2 * n, 1, n);

    ll current_max = 0;
    for (int k = 1; k <= 2 * n; ++k) {
        current_max = max(current_max, ans[k]);
        cout << current_max << (k == 2 * n ? "" : " ");
    }
    cout << nline;
}

signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
