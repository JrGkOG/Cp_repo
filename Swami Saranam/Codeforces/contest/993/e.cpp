#include <bits/stdc++.h>
#define ll  long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >> t; 
    while (t--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;       
        ll cur=1,ans=0;
        while(cur<=r2){
            const ll R=min(r2/cur,r1),L=max((l2+cur-1)/cur,l1);
            if(L<=R)
                ans+=R-L+1;
            cur*=k;
        }
        cout<<ans<<endl;
    }
    return 0;
}
