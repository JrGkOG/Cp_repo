#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

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
void solve() {
    //  we sort the elements based the reachind index 
    int n;cin>>n;
    vector<pair<int,int>>nums;
    for(int i=0;i<n;i++){
        int num1,num2;cin>>num1>>num2;
        nums.pb({num1,num2});
        // a.pb(num1);
        // b.pb(num2);
    }
    auto comp = [](pair<int, int> a, pair
                   <int,int> b) {
      	return a.second > b.second;
    };
    // sort(a.begin(),a.end());
    vector<int>a;
    sort(nums.begin(),nums.end(),comp);
    for(auto it:nums){
        // cout<<it.first<<endl;
        a.pb(it.first);
    }
    ordered_set os;
    int ans=0;
    for(int i=n-1;i>=0;i--){
        int smaller_or_equal = os.order_of_key(a[i] + 1);
        ans+=os.size() - smaller_or_equal;
        os.insert(a[i]);
    }
    cout<<ans<<endl;
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
