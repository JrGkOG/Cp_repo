#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define f(a,b) for(int i=a;i<=b;i++)
#define v(a) vector<a>
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.begin(),v.end(),greater<int>())
#define vv(a) vector<vector<a> >
#define af(v) for(auto &it:v)

v(int) prefix(v(int)& arr) {
    int n = arr.size();
    v(int) pre(n+1, 0);
    f(0,n-1) pre[i+1] = pre[i] + arr[i];
    return pre;
}

vv(int) prefixSum2D(vv(int)& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vv(int) pre(n+1, v(int)(m+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];

        }
    }
    return pre;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}


void solve(){
    int n,x;
    cin>>n>>x;
    v(int) vec(n);
    f(0,n-1)cin>>vec[i];
    if(n==1){
        if(vec[0]>=x)cout<<vec[0]<<endl;
        else cout<<0<<endl;
        cout<<vec[0]<<endl;
        return;
    }
    v(int) op;
    int ans=0;
    srt(vec);
    int i=0,j=n-1;
    int curr=vec[j];
    while(i<j){
        if(curr>=x){
            curr=0;
            ans+=vec[j];
            op.push_back(vec[j]);
            j--;
            curr+=vec[j];
        }
        else{
            curr+=vec[i];
            op.push_back(vec[i]);
            i++;
        }
    }
    if((curr)>=x){
        ans+=vec[j];
        op.push_back(vec[j]);
    }
    else{
        op.push_back(vec[j]);
    }
    cout<<ans<<endl;
    int m=op.size();
    f(0,m-1)cout<<op[i]<<" ";
    cout<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}