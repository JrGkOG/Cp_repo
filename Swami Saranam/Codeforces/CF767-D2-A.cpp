#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#define endl "\n"
#define PI 3.141592653
#define ll long long
#define ull unsigned long long
#define lld long double
#define ld long double
#define pb(x) push_back(x);
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fixed      \
    cout << fixed; \
    cout.precision(9)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define sza(r) ((int)r.size())
#define all(u) (u).begin(), (u).end()
#define ign cin.ignore(numeric_limits<std::streamsize>::max(), '\n')
#define home string::npos
#define ma_mod(a, n) ((a % n) + n) % n
#define cl(x, y) ((x + y - 1) / y)
#define ON(n, k) ((n) | (1 << k))
#define OFF(n, k) ((n) & (~(1 << k)))
#define isON(n, k) (((n) >> (k)) & 1)
using namespace std;
using namespace std::chrono;
//=================================================================
//-----------------------Output and input file---------------------
void File()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}
void Debug()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
}
//================================================================
//-------------------------Debug---------------------------------
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
//----------------------------------------------------------------
void _print(double t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(float t) { cerr << t; }
void _print(bool t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
//------------------------------------to make it visible to other _print---------------------------------------------------------
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T, class V>
void _print(vector<pair<T, V>> v);
template <class T>
void _print(vector<vector<T>> v);
template <class T, class V, class H>
void _print(vector<pair<T, pair<V, H>>> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(map<T, vector<V>> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(unordered_map<T, vector<V>> v);
template <class T>
void _print(deque<T> v);
template <class T>
void _print(queue<T> v);
template <class T>
void _print(priority_queue<T> v);
template <class T>
void _print(stack<T> v);
//---------------------------------------------------------------------------------------------------------------------------
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(vector<vector<T>> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        cerr << endl;
        _print(i);
        cerr << ",";
    }
    cerr << "]";
}
template <class T, class V>
void _print(vector<pair<T, V>> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        cerr << endl;
        _print(i);
    }
    cerr << "]";
}
template <class T, class V, class H>
void _print(vector<pair<T, pair<V, H>>> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        cerr << endl;
        _print(i);
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]" << endl;
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "{ ";
    for (auto i : v)
    {
        _print(i);
        cerr << ", ";
    }
    cerr << "}";
}
template <class T, class V>
void _print(map<T, vector<V>> v)
{
    cerr << "[ \n";
    for (auto i : v)
    {
        cerr << endl;
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, vector<V>> v)
{
    cerr << "[ \n";
    for (auto i : v)
    {
        cerr << endl;
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(deque<T> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(queue<T> v)
{
    cerr << "[ ";
    while (!v.empty())
    {
        _print(v.front());
        v.pop();
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(priority_queue<T> v)
{
    cerr << "[ ";
    while (!v.empty())
    {
        _print(v.top());
        v.pop();
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(stack<T> v)
{
    cerr << "[ ";
    while (!v.empty())
    {
        _print(v.top());
        v.pop();
        cerr << " ";
    }
    cerr << "]";
}
//=============================================================================================================================
//-----------------------------------directions array--------------------------------------------------------------------------
int di[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dj[] = {0, 0, 1, -1, 1, -1, -1, 1};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
//================================================================================================================================
//-----------------------------------some constant--------------------------------------------------------------------------------
const int SZ = 2*(1e5);
const ll CON = (1e18);
const ll inf = (1 << 30);
const int MOD = (1e9 + 7);
const int M = (3005);
//============================================================
// 1 sec = 10^8 operations
//============================================================
//--------------------leetcode--------------------------------
// int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
//============================================================
//------------------------------------------------------------
//============================================================
void testcase() 
{
   int n,temp;
   cin >> n;
   set <int, greater<int>> st;
   temp=n;
   for(int i=n;i>=1;i--){
    int x;
    cin >> x;
    if(temp==x){
        cout << x << " ";
        temp--;
        while(!st.empty()&&temp==*st.begin()){
            cout << *st.begin() << " ";
            st.erase(*st.begin());
            temp--;
        }
        cout << endl;
    }
    else{
        st.insert(x);
        cout << endl;
    }
   }

}
//=============================================================
int main()
{
    fast();
    //fixed;
    File();
    Debug();
    //=================================================================
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //=================================================================
    int t = 1;
    //cin >> t;
    while (t--)
    {
        // auto startTime = high_resolution_clock::now();
        testcase();
        // auto stopTime = high_resolution_clock::now();
        // auto duration = duration_cast<microseconds>(stopTime - startTime);
        // auto sec=duration.count()/1000000;
        // debug(sec);
    }
    //=================================================================
    return 0;
}
/*

 */