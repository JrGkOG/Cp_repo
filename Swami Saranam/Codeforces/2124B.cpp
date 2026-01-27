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
int getMinPrefix(vector<int> arr) {
    int sum=0;
    int mini=LLONG_MAX;
    for(int i=0;i<arr.size();i++){
        mini=min(arr[i],mini);
        sum+=mini;
    }
    return sum;
}
void solve() {
    int n;
    cin>>n;
    iv(a,n);
    int ans=getMinPrefix(a);
    vector<int> prefixSum(n);
    int mini=LLONG_MAX;
    int curr=0;

    for(int i=0;i<n;i++){
        mini=min(mini,a[i]);
        curr+=mini;
        prefixSum[i]=curr;
    }

    bool flag=true;
    for(int j=1;j<n;j++){
        if(j>1 && a[j-1]>=a[j-2]) flag=false;
        int cost=0;
        if(!flag) cost=prefixSum[j-1];
        else{
            int minCost=LLONG_MAX;
            for(int i=0;i<j;i++){
                vector<int> temp(a.begin(),a.begin()+j);
                temp[i]+=a[j];
                minCost=min(minCost,getMinPrefix(temp));
            }
            cost=minCost;
        }
        ans=min(ans,cost);
    }
    cout<<ans<<endl;
}
void solve2(){
    int n;
    cin>>n;
    iv(v,n);
    cout<<min(2*v[0],v[0]+v[1])<<endl;
}

signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve2();
    return 0;
}