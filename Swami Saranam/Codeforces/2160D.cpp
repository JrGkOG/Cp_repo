// karthik solving bois
#include <bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) x.begin(),x.end()

int ask(const vector<int>&v){
    if(v.empty()) return 0;
    cout<<"? "<<sz(v);
    for(auto x:v) cout<<" "<<x;
    cout<<endl; cout.flush();
    int r; cin>>r;
    if(r==-1) exit(0);
    return r;
}

void out(const vector<int>&a){
    cout<<"! ";
    for(int i=0;i<sz(a);i++) cout<<a[i]<<(i+1==sz(a)?'\n':' ');
    cout.flush();
}

void solve(){
    int n;cin>>n;
    vector<int>a(2*n,0);
    vector<int>paired(2*n+1,0);

    // step1: check adjacent pairs
    for(int i=1;i<=n;i++){
        int x=2*i-1,y=2*i;
        int v=ask({x,y});
        if(v>0){
            a[x-1]=v; a[y-1]=v;
            paired[x]=paired[y]=1;
        }
    }

    // collect unpaired
    vector<int>u;
    for(int i=1;i<=2*n;i++) if(!paired[i]) u.pb(i);

    // process groups
    vector<int> reps;
    int knownSum=accumulate(all(a),0);

    for(int idx=0; idx<sz(u); idx++){
        int cur=u[idx];

        // last-two trick
        if(sz(reps)==1 && idx==sz(u)-1){
            int total=n*(n+1);
            int miss=(total-knownSum)/2;
            int par=reps[0];
            a[cur-1]=miss;
            a[par-1]=miss;
            break;
        }

        if(reps.empty()){
            reps.pb(cur);
            continue;
        }

        vector<int> q=reps; q.pb(cur);
        int v=ask(q);

        if(v==0){
            reps.pb(cur);
        }else{
            // find correct group rep (in order)
            for(int j=0;j<sz(reps);j++){
                int rep=reps[j];
                int vv=ask({rep,cur});
                if(vv==v){
                    a[cur-1]=v;
                    a[rep-1]=v;
                    knownSum+=2*v;
                    reps.erase(reps.begin()+j);
                    break;
                }
            }
        }
    }

    out(a);
}

signed main(){
    fast();
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
