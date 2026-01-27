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
void solve() {int n;
    cin>>n;
    priority_queue<int> odd,even;
    iv(v,n);
    for(int i=0;i<n;i++){
        if(v[i]&1) odd.push(v[i]);
        else even.push(v[i]);
    }
    int cntOdd=odd.size();
    int cntEven=even.size();

    vector<int> evenList;
    while(!even.empty()){
        evenList.push_back(even.top());
        even.pop();
    }
    vector<int> evenPref(cntEven+1);
    for(int i=1;i<=cntEven;i++) evenPref[i]=evenPref[i-1]+evenList[i-1];
    vector<int> ans(n+1);
    for(int k=1;k<=n;k++){
        int ce=min(k-1,cntEven);
        int co=k-ce;
        if(co%2==0){
            ce--;
            co++;
        }
        if(ce<0||co<1||co>cntOdd){
            ans[k]=0;
            continue;
        }
        int bestOdd=odd.top();
        int need=ce;
        int sumEven=0;
        // vector<int> temp1;
        // while(need>0){
        //     int x=even.top();
        //     even.pop();
        //     temp1.push_back(x);
        //     sumEven+=x;
        //     need--;
        // }
        // for(int x:temp1) even.push(x);
        sumEven = evenPref[ce];
        ans[k]=bestOdd+sumEven;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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
