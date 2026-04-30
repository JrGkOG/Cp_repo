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
void solve() {
    int n;cin>>n;
    vector<int>nums;
    vector<int>temp;
    vector<int>two;
    vector<int>thr;
    for(int i=0;i<n;i++){
        int num;cin>>num;
        if(num%6==0){
            nums.push_back(num);
        }
        else if(num%2==0){
            two.pb(num);
        }
        else if(num%3==0){
            thr.pb(num);
        }
        else temp.pb(num);
    }
    // }
    // sort(nums.begin(),nums.end());
    // sort(temp.begin(),temp.end());
    // sort(two.begin(),two.end)
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    for(int i=0;i<two.size();i++){
        cout<<two[i]<<" ";
    }
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    for(int i=0;i<thr.size();i++){
        cout<<thr[i]<<" ";
    }
    cout<<endl;
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
