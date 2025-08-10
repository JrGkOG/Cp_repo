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
vector<vector<pair<ll,ll>>> adj;
vector<vector<ll>> adj_unweighted;
vector<ll> dist;
vector<bool> visited;

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

void init_graph_weighted(ll n) {
    adj.assign(n + 1, {});
    dist.assign(n + 1, INF);
    visited.assign(n + 1, false);
}

void dfs(ll u) {
    visited[u] = true;
    for (ll v : adj_unweighted[u]) {
        if (!visited[v]) dfs(v);
    }
}

void bfs(ll start) {
    queue<ll> q;
    dist.assign(sz(adj_unweighted), INF);
    visited.assign(sz(adj_unweighted), false);
    dist[start] = 0;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v : adj_unweighted[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void dijkstra(ll start) {
    dist.assign(sz(adj), INF);
    dist[start] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
void solve() {
    ll n;
    cin>>n;
    vector<int>ans(n,-1);
    int negative=ceil(n/2);
    if(n==2) cout<<-1<<" "<<2<<endl;
    else if(n==3) cout<<-1<<" "<<3<<" "<<-1<<endl;
    else {
        if(n%2==0){
            for(int i=1;i<=n-1;i++){
                if(i%2==0) cout<<3<<" ";
                else cout<<-1<<" ";
            }
            cout<<2<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                if(i%2==0) cout<<3<<" ";
                else cout<<-1<<" ";
            }
            cout<<endl;
        }
    }
}

signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
