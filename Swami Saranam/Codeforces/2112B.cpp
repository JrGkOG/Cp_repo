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
        ll n;
        cin >> n;
        iv(nums, n);
        bool flag=false;
        f(i,n-1){
            if(abs(nums[i]-nums[i+1]) <=1 ) flag=true;
        }   
        if(flag)cout<<0<<endl;
        else{
            if(n<=2) cout<<-1<<endl;
            else{
                bool poss=false;
                f(i,n-1){
                    if(i>0 && max(nums[i],nums[i+1]) +1 >=nums[i-1] && min(nums[i],nums[i+1]) <= nums[i-1]+1 )poss=true;
                    if(i < n-2 && max(nums[i], nums[i+1]) + 1 >= nums[i+2] && min(nums[i], nums[i+1]) <= nums[i+2] + 1) poss = true;
                }
                if(poss) cout<<1<<endl;
                else cout<<-1<<endl;
            }
        }
    }
}

int main(){
    fast();
    func();
    return 0;
}
