int getIdx(vector<int> &a,int v){
    auto it = lower_bound(a.begin(),a.end(),v);
    if(it!=a.end() && *it==v) return it - a.begin();
    return -1;
}
void solve(){
    int n,k; cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    int m = a.size();

    vector<bool> visited(m,false);
    vector<int> b;

    for(int i=0;i<m;i++){
        if(visited[i]) continue;
        int x = a[i];
        bool flag = true;

        if(k/x > m) flag = false;
        else{
            for(int j=1;;j++){
                int v = x * j;
                if(v > k) break;
                if(getIdx(a,v) == -1){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag){
            cout<<-1<<endl;
            return;
        }
        b.push_back(x);
        for(int j=1;;j++){
            int v = x * j;
            if(v > k) break;
            if(v > a.back()) break;
            int idx = getIdx(a,v);
            if(idx != -1) visited[idx] = true;
        }
    }
    cout<<b.size()<<endl;
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<(i+1==b.size()?"":" ");
    }
    cout<<endl;
}