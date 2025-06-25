    #include <bits/stdc++.h>
    using namespace std;
    #define fast()                        \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);   
    #define ll long long
    #define f(i, n) for (ll i = 0; i < n; i++)
    #define ia(a, n) \
        ll a[n];     \
        f(i, n) cin >> a[i]
    #define iv(v, n)     \
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
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            iv(v,n);
            sort(v.begin(),v.end()); 
            ll ans=0;
            ll maxi1=v[n-1];
            ll maxi2=v[n-2];
            for(int i=2;i<n;i++){
                ll temp1= 2*v[i];
                ll temp2= (i==n-1) ? maxi2 : maxi1;
                ll temp = max(temp1,temp2);
                ll find=temp-v[i];
                ll l=0;
                ll r=i-1;
                while(l<r){
                    if(v[l] + v[r] > find) {
                        ans+=r-l;
                        r--;
                    }else{
                        l++;
                    }
                }
            }    
            cout<<ans<<endl;  
        }
    }
    int main(){
        fast();
        func();
        return 0;
    }