#include <bits/stdc++.h>
#define fast()                        \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
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

void solve() {
    string s;
    cin>>s;
    if(s=="first"){
        int t;cin>>t;
        while(t--){
            int v,m;
            cin>>v>>m;
            vector<vector<int>>adj(v);
            for(int i=0;i<m;i++){
                int u,w;
                cin>>u>>w;
                u--;
                w--;
                adj[u].pb(w);
                adj[w].pb(u);
            }
            vector<bool> visited(v, false);
            vector<int> res(v,-1);
            queue<int> q;
            for (int start = 0; start < v; start++) {
                if (visited[start]) continue;

                visited[start] = true;
                res[start] = 0;
                q.push(start);

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int x : adj[curr]) {
                        if (!visited[x]) {
                            visited[x] = true;
                            res[x] = (res[curr] + 1) % 3;
                            q.push(x);
                        }
                    }
                }
            }
            // rgbbbgr
            // rggb
            for(int i=0;i<res.size();i++){
                if(res[i]==0) cout<<'r';
                if(res[i]==1) cout<<'g';
                if(res[i]==2) cout<<'b';
            }
            cout<<endl;
        }
    }
    else{
        // cout<<s<<endl;
        int tst;cin>>tst;
        while(tst--){
            int q;cin>>q;
            while(q--){
                int siz;cin>>siz;
                string str;cin>>str;
                bool r=false;
                bool g=false;
                bool b=false;
                for(char c:str){
                    if(c=='r') r=true;
                    if(c=='g') g=true;
                    if(c=='b') b=true;
                }
                char target=' ';
                if(r&g) target='g';
                else if(b&g)target='b';
                else if(r&b)target='r';
                else if(r)target='r';   
                else if(g)target='g';
                else if(b)target='b';
                // cout<<target<<endl;
                for(int i=0;i<str.size();i++){
                    if(str[i]==target){
                        cout<<i+1<<endl;
                        break;
                    }
                }
            }
        }
    }
}
signed main() {
    fast();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
