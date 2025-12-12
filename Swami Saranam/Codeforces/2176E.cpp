#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;

    vector<int>a(n+1), c(n+1), p(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>p[i];

    vector<int> alive(n+1, 1), left(n+1), right(n+1);

    for(int i=1;i<=n;i++){
        left[i] = i-1;
        right[i] = i+1;
    }
    right[n] = 0;

    priority_queue< tuple<int,int,int>,
                    vector< tuple<int,int,int> >,
                    greater< tuple<int,int,int> > > pq;

    // push all initial adjacent pairs
    for(int i=1;i<n;i++){
        pq.push({min(c[i],c[i+1]), i, i+1});
    }

    ll ans = 0;
    int removed = 0;

    while(removed <= n-2){

        if(pq.empty()) break;

        auto t = pq.top();
        pq.pop();

        int L = get<1>(t);
        int R = get<2>(t);

        if(!alive[L] || !alive[R]) continue;

        int rem, surv;

        // ✔ REAL RULE: REMOVE BASED ON VALUE
        if(a[L] < a[R]) rem = L, surv = R;
        else if(a[R] < a[L]) rem = R, surv = L;
        else {
            // values equal → choose ANY, we choose lower cost survivor
            if(c[L] <= c[R]) rem = L, surv = R;
            else rem = R, surv = L;
        }

        // ✔ COST PAID: min(c[L], c[R])
        ans += min(c[L], c[R]);

        alive[rem] = 0;
        removed++;

        int Lp = left[rem];
        int Rp = right[rem];

        // ✔ MERGING SURVIVOR WITH REM'S NEIGHBORS
        if(rem == L){
            left[R] = Lp;
            if(Lp) right[Lp] = R;

            // new pair: (Lp, R)
            if(Lp) pq.push({min(c[Lp], c[R]), Lp, R});
        }
        else { // rem == R
            right[L] = Rp;
            if(Rp) left[Rp] = L;

            // new pair: (L, Rp)
            if(Rp) pq.push({min(c[L], c[Rp]), L, Rp});
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
