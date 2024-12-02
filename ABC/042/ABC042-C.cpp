#include <bits/stdc++.h>

using namespace std;

bool isValid(int number, const vector<bool>& disliked) {
    string numStr = to_string(number);
    for (char c : numStr) {
        if (disliked[c - '0']) { // Check if the digit is disliked
            return false;
        }
    }
    return true;
}

int main() {
    int N, K;
    cin >> N >> K; // Input the total amount N and the number of disliked digits K

    vector<bool> disliked(10, false); // Initialize a vector<bool> to track disliked digits
    for (int i = 0; i < K; ++i) {
        int d;
        cin >> d; // Input each disliked digit
        disliked[d] = true;
    }

    int amount = N; // Start checking from N
    while (!isValid(amount, disliked)) {
        ++amount; // Increment until a valid amount is found
    }

    cout << amount << endl; // Output the minimum valid amount
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int N,K; cin >> N >> K;
//     int ng = 0;
//     while(K--){
//         int d; cin >> d;
//         ng += 1<<d;
//     }

//     for(int i=N; ; i++){
//         int ap = 0,x = i;
//         while(x) ap |= 1<<(x%10),x /= 10;
//         if(ap&ng) continue;
//         cout << i << endl; break;
//     }
// }

