#include <bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) ll a[n]; f(i, n) cin >> a[i]
#define iv(v, n) vector<ll> v(n); f(i, n) cin >> v[i]
#define MOD 1000000007
#define INF 1000000000000000000LL
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

bool check(vector<ll> v) {
    ll s=0;
    for (ll i=0; i<v.size(); i++) {
        s+=v[i];
        if (s%3==0) return false;
    }
    return true;
}

void func() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i=0; i<n; i++) cin >> arr[i];
        vector<int> prefix(n);
        prefix[0]=arr[0]%3;
        for (int i=1; i<n; i++) prefix[i]=(prefix[i-1]+arr[i])%3;
        bool flag=true;
        for (int i=0; i<n; i++) {
            if (prefix[i]==0) {
                flag=false;
                break;
            }
        }
        if (flag) {
            cout << "Yes\n";
            continue;
        }
        bool found=false;
        for (int len=1; len<=n && !found; len++) {
            bool flag2=true;
            int sum=0;
            for (int i=len-1; i>=0; i--) {
                sum+=arr[i];
                if (sum%3==0) {
                    flag2=false;
                    break;
                }
            }
            if (flag2) {
                for (int i=len; i<n; i++) {
                    sum+=arr[i];
                    if (sum%3==0) {
                        flag2=false;
                        break;
                    }
                }
            }
            if (flag2)found=true;
        }
        if(found)yes;
        else no;
    }
}

int main() {
    fast();
    func();
    return 0;
}
