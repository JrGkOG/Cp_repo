#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long
#define f(i, n) for (int i = 0; i < (n); i++)
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
#define sor(v) sort(v.begin(), v.end())
#define rsor(v) sort(v.begin(), v.end(), greater<>())
#define rev(v) reverse(v.begin(), v.end())
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
// muruga enna kapathu
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2==0&&n>=2){
        if(s[0]==s[1] &&s[0]!='?'){
            no
            return;
        }
    }
    int cnt=0;
    if(n%2==1){
        if(s[0]=='b'){
            no
            return;
        }
        cnt=1;
    }
    for(int i=cnt;i<n;i+=2){
        if(i+1>=n)break;
        char a=s[i];
        char b=s[i+1];
        if(a!='?'&&b!='?'&&a==b){
            no
            return;
        }
    }
    yes
    // int countA=0,countB=0,countQ=0;

    // for(char c:s){
    //     if(c=='a')countA++;
    //     else if(c=='b')countB++;
    //     else countQ++;
    // }

    // int targetA,targetB;

    // if(n%2==0){
    //     targetA=n/2;
    //     targetB=n/2;
    // }
    // else{
    //     targetA=n/2+1;
    //     targetB=n/2;

    //     if(s[0]=='b'){
    //         no
    //         return;
    //     }

    //     if(s[0]=='?'){
    //         s[0]='a';
    //         countA++;
    //     }
    // }

    // if(countA>targetA||countB>targetB){
    //     no
    //     return;
    // }

    // for(int i=0;i<n;i++){
    //     if(s[i]=='?'){
    //         if(i>=2&&s[i-1]==s[i-2]){
    //             s[i]=(s[i-1]=='a')?'b':'a';
    //         }
    //         else{
    //             if(countA<targetA)s[i]='a';
    //             else s[i]='b';
    //         }

    //         if(s[i]=='a')countA++;
    //         else countB++;
    //     }

    //     if(i>=2&&s[i]==s[i-1]&&s[i]==s[i-2]){
    //         no
    //         return;
    //     }
    // }

    // if(countA==targetA&&countB==targetB)yes
    // else no
}
signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
