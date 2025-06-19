#include <bits/stdc++.h>

#include <limits.h>
using namespace std;

#define ll long long
#define fr(i, start, end) for(ll i = start; i < end; i++)

/*
orderd set -> policy based data structure
int → Data type of elements.
null_type → Since it's a set, no mapped values are needed.
less<int> → Maintains elements in ascending order (use greater<int> for descending).
rb_tree_tag → Implements a Red-Black Tree.
tree_order_statistics_node_update → Enables order statistics operations.

s.insert(x) O(log n): Inserts x. 
s.erase(x) O(log n): Erases x. 
s.find(x) O(log n): Returns iterator to x or s.end(). 
s.lower_bound(x) O(log n): First element ≥ x.
s.upper_bound(x) O(log n): First element > x. 
s.size() O(1): Returns size. 
s.begin() O(1): First element. 
s.end() O(1): One past last. 
s.order_of_key(x) O(log n): Number of elements < x. 
s.find_by_order(k) O(log n): Returns iterator to k-th smallest element (0-based).
*/ 


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class DisjointSet{
    // tc -> o(1) for both
    vector<ll> parent;
    vector<ll> size;
    public:
    DisjointSet(ll V){
        parent.resize(V);
        size.resize(V);
        fr(i,0,V){parent[i]=i;size[i]=1;}
    }
    void unionSize(ll u,ll v){
        ll ulp_v = findParent(v);
        ll ulp_u = findParent(u);
        if(ulp_v!=ulp_u){
            if(size[ulp_u]>=size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
            else{
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];                
            }
        }
    }
    ll findParent(ll u){ // path compression
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }
};


 
const int n1=1e9+7;
 
ll gcd(ll a,ll b){
    if(a == 0) return b;
    if(a>b) return gcd(b,a);
 
    return gcd(b%a,a);
}

bool ask(string t) {
    cout << "? " << t << endl;
    int res;
    cin >> res;
    return res;
}
 
void result(string s) {
    cout << "! " << s << endl;
}
 
bool cmp(pair<ll,ll> &a, pair<ll,ll> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
 
    return a.first > b.first;
}
 
bool is_fair(long long x) {
    long long temp = x;
    while (temp > 0) {
        int digit = temp % 10;
        temp /= 10;
        if (digit != 0 && x % digit != 0) {
            return false;
        }
    }
    return true;
}
 
ll integerSqrt(ll x) {
    if (x == 0 || x == 1) return x;
    
    ll left = 1, right = x, ans = 1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        
        // To prevent overflow in mid * mid, we use division
        if (mid <= x / mid) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
 
bool check(ll w, ll sI, ll sI2, ll n, ll c) {
    // Calculate the total area used by this w
    ll usedArea = n * w * w + 2 * w * sI + sI2;
    return usedArea <= c;
}
 
vector<ll> best3(vector<ll> &x){
    ll n = x.size();
    ll mx1,mx2,mx3;
    mx1 = -1;
    mx2 = -1;
    mx3 = -1;
 
    fr(i,0,n){
        if(mx1==-1 or x[i] > x[mx1]){
            mx3 = mx2;
            mx2 = mx1;
            mx1 = i;
        }
        else if(mx2 == -1 or x[i] > x[mx2]){
            mx3 = mx2;
            mx2 = i;
        }
        else if(mx3 == -1 or x[i]>x[mx3]){
            mx3 = i;
        }
    }
 
    return vector<ll>{mx1,mx2,mx3};
 
 
}
 
ll factorial(ll n){
    ll ans = 1;
    while(n){
        ans*=n;
        ans%=998244353;
        n--;
    }
    return ans;
}
   
bool f(vector<ll> &v,ll h){
    ll i = v.size()-1;
    sort(v.begin(),v.end());

    while(i >= 0){
        if(v[i]>h){
            return false;
        }
        h-=v[i];
        i-=2;
    }
    return true;
}
// to watch videos that give you the sensation of understanding , without actually learning anything
// u have to be willing to be uncomfortable to become an expert
void dfs(ll curr,ll clr ,ll prev ,vector<vector<ll>> &a,ll &cnt,ll &cntR,ll &cntB){
    if(clr == 1) cntR++;
    else cntB++;

    for(auto it : a[curr]){
        if(it == prev) continue;
        cnt++;
        dfs(it,!clr,curr,a,cnt,cntR,cntB);
    }
}

void getPrimeFactors(int n,map<ll,ll> &m){ 
    // Declare a vector to store
    // the prime factors of n.
    vector<int> primeFactors; 
    // m[1]++;
    // Loop from 2 up to n
    for(int i = 2; i <= n; i++){
        // Check if n is divisible by i

        // Continue dividing n by i
        // until it's no longer divisible
        while(n % i == 0){
            n = n / i;
            m[i]++;
        }
    }
    // Return the vector
    // containing the prime factors of n.
    return;
}

ll f(ll curr,vector<vector<ll>> &adj,set<ll> &s){
    ll n = adj.size() - 1;
    ll ans = curr;
    for(auto rN : adj[curr]){
        if(s.find(rN) != s.end()) continue;
        s.insert(rN);
        ans = max(ans,f(curr+1,adj,s));
        s.erase(rN);
    }
    return ans;
}   

struct hasher{
    int n, _k, _p;
    vector<int> powk,base,rev;
    
    void init(string s,int k,int p){
        _k = k, _p = p;
        n = s.length();
        powk.resize(n+1);
        base.resize(n+1);
        
        // precompute
        base[0] = 0;
        powk[0] = 1;
        for(int i=0;i<n;i++){
            int num = (s[i]-'a'+1 )%p;
            base[i+1] = (1LL *base[i] * k + num)%p;
            powk[i+1] = (1LL* k * powk[i]) %p;
        }
        
        // reverse
        rev.resize(n+1);
        rev[n] = 0;
        for(int i=n-1;i>=0;i--){
            int num = (s[i]-'a'+1 )%p;
            rev[i] = (1LL *rev[i+1] * k + num)%p;
        }
    }  
    int gethash(int l,int r){ // 0 index
        int ans = (base[r+1] - 1LL *base[l]*powk[(r-l+1)])%_p;
        return (ans+_p)%_p;
    }
    // reverse hash
    int getrevhash(int l,int r){
        int ans = (rev[l] - 1LL *rev[r+1]*powk[(r-l+1)])%_p;
        return (ans+_p)%_p;
    }
};
 
struct double_hash{
    hasher a,b;
    string _s;
    void init(string s){
        a.init(s,37,1000000021);
        b.init(s,39,1000000009);
        _s = s;
    }
    pair<int,int> gethash(int l,int r){
        return {a.gethash(l,r),b.gethash(l,r)};
    }
    pair<int,int> getrevhash(int l,int r){
        return {a.getrevhash(l,r),b.getrevhash(l,r)};
    }
    bool is_palin(int l,int r){
        return gethash(l,r) == getrevhash(l,r);
    }
    bool is_lex_smaller(int i,int j,int len){
        // return 0 if i one smaller else return one for j substring smaller
        int ans = 0;
        int lw = 1; // rep common len
        int hi = len;
        while(lw<=hi){
            int mid = lw + (hi - lw )/2;
            if(gethash(i,i+mid-1) == gethash(j,j+mid-1)){
                ans = mid;
                lw = mid + 1;
            }
            else{
                hi = mid-1;
            }
        }   
        if(ans == len) return 0;
        else return _s[i+ans]>_s[j+ans];
    }
};

vector<ll> nfct(15,1);
ll f(ll num,ll idx){
    if(idx == 15){
        if(num == 0) return 0;
        else{
            ll x = 0;
            fr(i,0,45){
                if(num&(1LL<<i)){
                    x++;
                }
            }
            return x;
        }
    }

    ll val = f(num,idx+1);
    if(nfct[idx]<=num){
        val = min(val,1+f(num-nfct[idx],idx+1));
    }
    return val;
}
void generatePalindrome(vector<ll> &nums){
    fr(i,1,10){
        nums.push_back(i);
    }
    for(ll i = 11 ; i<=99;i+=11){
         nums.push_back(i);
    }
    fr(i,1,10){
        ll num = i*100;

        fr(j,0,10){
            ll val = j*10;
            ll nber = num+i+val;
            nums.push_back(nber);
        }
    }
   fr(i,1,10){
        ll num = i*1000+i;
        for(ll k = 0 ; k<=99;k+=11){
                ll nber = num + k*10;
                nums.push_back(nber);
        }
    }
  fr(i,1,4){
        ll mn = i*10000+i;
        fr(r,0,10){
            ll dig3 = r*100+r;
            fr(j,0,10){
                ll val = j*10;
                ll nber = mn + (dig3+val)*10;
                nums.push_back(nber);
            }
        }
    }    
    return;
}


//if can invite x number of people
bool f(ll x,vector<ll> &a,vector<ll> &b){
    ll taken=0,to_take=x;
    fr(i,0,a.size()){
        if(to_take==0) break;
        if(a[i]>=to_take-1 and b[i]>=taken){
            taken++; to_take--;
        }
    }
    
    
    return to_take==0;
}

// int gcds[5001][5001];
// fr(i,1,5001){
//     fr(j,1,5001){
//         gcds[i][j] = gcd(i,j);
//     }
// }
const int N = 5000 + 5;

int main(){

    
    int test = 1;
    cin >> test;

    while (test--) {
        
        
        ll n,m,k;
        cin >> n>>m;
        vector<ll> fibo(n+1);
        fibo[0] = 1;
        if (n >= 1) fibo[1] = 1;
        for (int i = 2; i <= n; i++) {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
        vector<pair<ll,pair<ll,ll>>> v;
        string s;
        fr(i,0,m) s+='0';
        fr(i,0,m){
            ll w,l,h;
            cin>>w>>l>>h;
            ll mini = min({w,l,h});
            ll maxi = max({w,l,h});
            
            ll num = fibo[n];
            ll num1 = fibo[n-1];
            if(mini>=num and num+num1<=maxi)
            {
                s[i] = '1';
            } 
            else{
                //pass
            }
        }

        cout<<s<<endl;

        
        
        
        
        // sort(a.begin(),a.end());
        // bool ans = false;
        // fr(i,1,n-1){
        //     if(a[i]==a[i-1]){
        //         ll j = (a[i+1]==a[i])? i+2:i+1;
        //         while(j<n and a[j]-a[j-1]==1){
        //             j++;
        //         }
        //         if(j<n and a[j]==a[j-1]){
        //             ans = true;
        //             break;
        //         }
        //         else{
        //             i = j;
        //         }
        //     }
        // }
        
        // if(ans){
        //     cout<<"YES"<<endl;
        // }
        // else{
        //     cout<<"NO"<<endl;
        // }
        
        // ll ans = 1;
        // ll l = 1;
        // ll r = n;
        // while(l<=r){
        //     ll mid = l + (r-l)/2;
            
        //     if(f(mid,a,b)){
        //         ans = mid;
        //         l = mid + 1;
        //     }
        //     else{
        //         r = mid - 1;
        //     }
        // }
        
        
        // cout<<ans<<endl;
        

    }
    
    return 0;

}