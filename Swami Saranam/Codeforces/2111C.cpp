#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll>v(n);
        for(ll i=0;i<n;i++) cin>>v[i];
        ll ans = LLONG_MAX;
        ll j = 0;
        for(ll i = 0; i < n; i++) {
            while(j < n && v[i] == v[j]) {
                j++;
            }
            ans = min(ans, (n-j+i)*v[i]);
            i = j-1;
        }
        cout << ans << endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}