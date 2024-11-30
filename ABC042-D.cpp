// #pragma GCC optimize("Ofast") 
// #include <bits/stdc++.h> 
// using namespace std;

// // Macro Definitions to streamline the code

// #define INIT() std::ios::sync_with_stdio(false);std::cin.tie(0); // Optimize input/output speed
// #define Rep(i,n) for (int i = 0; i < (n); ++i) // Loop from 0 to n-1
// #define For(i,s,t) for (int i = (s); i <= (t); ++i) // Loop from s to t inclusive
// #define rFor(i,t,s) for (int i = (t); i >= (s); --i) // Loop from t down to s inclusive
// #define ForLL(i, s, t) for (LL i = LL(s); i <= LL(t); ++i) // Loop for long long from s to t inclusive
// #define rForLL(i, t, s) for (LL i = LL(t); i >= LL(s); --i) // Loop for long long from t down to s inclusive
// #define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i) // Iterate over container c
// #define rforeach(i,c) for (__typeof(c.rbegin()) i = c.rbegin(); i != c.rend(); ++i) // Reverse iterate over container c

// // Debugging Macros
// #define pr(x) cout << #x << " = " << x << "  " // Print the variable x and its value
// #define prln(x) cout << #x << " = " << x << endl // Print the variable x and its value with a new line

// #define LOWBIT(x) ((x)&(-x)) // Get the lowest bit of x

// // Useful Macros for containers
// #define ALL(x) x.begin(),x.end() // Get the entire range of a container x
// #define INS(x) inserter(x,x.begin()) // Insert elements at the beginning of a container

// // Memory Setting Macros
// #define ms0(a) memset(a,0,sizeof(a)) // Set all elements of array a to 0
// #define msI(a) memset(a,inf,sizeof(a)) // Set all elements of array a to infinity
// #define msM(a) memset(a,-1,sizeof(a)) // Set all elements of array a to -1

// // Macros for commonly used types and data structures
// #define MP make_pair // Create a pair
// #define PB push_back // Push an element to the back of a vector
// #define ft first // First element of a pair
// #define sd second // Second element of a pair

// // Input and Output Stream Overloads for custom types
// template<typename T1, typename T2>
// istream &operator>>(istream &in, pair<T1, T2> &p) {
//     in >> p.first >> p.second;
//     return in;
// }

// template<typename T>
// istream &operator>>(istream &in, vector<T> &v) {
//     for (auto &x: v)
//         in >> x;
//     return in;
// }

// template<typename T1, typename T2>
// ostream &operator<<(ostream &out, const std::pair<T1, T2> &p) {
//     out << "[" << p.first << ", " << p.second << "]" << "\n";
//     return out;
// }

// // Typedefs for common types
// typedef long long LL; // Long long type
// typedef unsigned long long uLL; // Unsigned long long type
// typedef pair< double, double > PDD; // Pair of double type
// typedef pair< int, int > PII; // Pair of integer type
// typedef set< int > SI; // Set of integers
// typedef vector< int > VI; // Vector of integers
// typedef map< int, int > MII; // Map of integers
// const double EPS = 1e-10; // Epsilon value for floating point comparison
// const int inf = 1e9 + 9; // Infinity value for comparison
// const LL mod = 1e9 + 7; // Modulo value for large numbers
// const int maxN = 1e5 + 7; // Maximum array size
// const LL ONE = 1; // Constant value 1
// const LL evenBits = 0xaaaaaaaaaaaaaaaa; // Mask with even bits set
// const LL oddBits = 0x5555555555555555; // Mask with odd bits set

// LL fac[2 * maxN]; // Factorial array, used for combinatorics

// // Function to initialize factorials
// void init_fact() {
//     fac[0] = 1; // Base case
//     For(i, 1, 2 * maxN - 1) { // Loop to calculate factorials modulo mod
//         fac[i] = (i * fac[i - 1]) % mod; // Calculate factorial
//     }
// }

// // Extended Euclidean Algorithm to calculate GCD and coefficients
// inline void ex_gcd(LL a, LL b, LL &x, LL &y, LL &d){
//     if (!b) {d = a, x = 1, y = 0;} // Base case: gcd(a, 0) = a
//     else{
//         ex_gcd(b, a % b, y, x, d); // Recursive call
//         y -= x * (a / b); // Update coefficients
//     }
// }   

// // Function to find the modular inverse of a with respect to p using extended Euclidean algorithm
// inline LL inv_mod(LL a, LL p){
//     LL d, x, y;
//     ex_gcd(a, p, x, y, d); // Calculate GCD and coefficients
//     return d == 1 ? (x % p + p) % p : -1; // Return the modular inverse if exists, otherwise -1
// }

// // Function to calculate (x^y) % p using binary exponentiation
// inline LL pow_mod(LL x, LL y, LL p){
//     LL ans = 1;
//     while(y){ // While exponent is greater than 0
//         if(y & 1) ans = (ans * x) % p; // If exponent is odd, multiply answer by x
//         x = (x * x) % p; // Square x
//         y >>= 1; // Right shift exponent (divide by 2)
//     }
//     return ans; // Return the result
// } 

// // Function to calculate binomial coefficient C(m, n) % mod
// inline LL comb_mod(LL m,LL n){
//     LL ans;
//     if(m > n) swap(m, n); // Ensure m <= n

//     // Calculate the combination using factorial and modular inverse
//     ans = (fac[n] * inv_mod(fac[m], mod)) % mod; 
//     ans = (ans * inv_mod(fac[n - m], mod)) % mod;
    
//     return ans; // Return the result
// }

// int H, W, A, B; // Input variables for grid dimensions and other parameters
// LL ans; // Variable to store the final result

// int main(){
//     INIT(); // Initialize input/output optimizations
//     init_fact(); // Initialize factorial array
//     cin >> H >> W >> A >> B; // Read input values for H, W, A, B

//     // Loop through the grid and compute the result using combinations
//     For(i, 1, H - A) {
//         // Calculate the combination for each position and add it to the result
//         ans += (comb_mod(i - 1, i + B - 2) * comb_mod(W - B - 1, W - B + H - i - 1)) % mod;
//         ans %= mod; // Take result modulo mod to avoid overflow
//     }
    
//     cout << ans << endl; // Output the final result
//     return 0; // Return 0 to indicate successful execution
// }

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7; // Modulo value for large numbers
const int maxN = 1e5 + 7; // Maximum array size

long long fac[2 * maxN]; // Factorial array, used for combinatorics

// Function to initialize factorials up to 2 * maxN
void init_fact() {
    fac[0] = 1;
    for (int i = 1; i < 2 * maxN; ++i) {
        fac[i] = (i * fac[i - 1]) % mod; // Store factorial values modulo mod
    }
}

// Extended Euclidean Algorithm to calculate GCD and modular inverse
void ex_gcd(long long a, long long b, long long &x, long long &y, long long &d){
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    } else {
        ex_gcd(b, a % b, y, x, d);
        y -= x * (a / b);
    }
}

// Find modular inverse of a number under modulo p
long long inv_mod(long long a, long long p){
    long long d, x, y;
    ex_gcd(a, p, x, y, d);
    return (d == 1) ? ((x % p + p) % p) : -1; // If inverse exists, return it
}

// Calculate x^y % p using modular exponentiation
long long pow_mod(long long x, long long y, long long p){
    long long ans = 1;
    while (y) {
        if (y & 1) ans = (ans * x) % p; // Multiply when y is odd
        x = (x * x) % p; // Square x
        y >>= 1; // Right shift y
    }
    return ans;
}

// Calculate combinations (n choose k) % mod
long long comb_mod(long long m, long long n){
    if (m > n) swap(m, n); // Ensure m <= n
    long long ans = (fac[n] * inv_mod(fac[m], mod)) % mod;
    ans = (ans * inv_mod(fac[n - m], mod)) % mod;
    return ans;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    // Initialize factorials
    init_fact();
    int H, W, A, B;
    cin >> H >> W >> A >> B; 
    long long ans = 0;
    for (int i = 1; i <= H - A; ++i) {
        // For each valid row, calculate number of ways to go from top-left to bottom-right
        ans += (comb_mod(i - 1, i + B - 2) * comb_mod(W - B - 1, W - B + H - i - 1)) % mod;
        ans %= mod; // Keep the result within bounds using modulo
    }
    
    cout << ans << endl; // Output the final result
    return 0;
}
