
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int T = 1; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        int bad = -1, margin = 1e9, need = 0;
        bool reject = 0;
        for (int i = 0; i < N; i++) {
            cin >> B[i];
            if (A[i] < B[i]) {
                if (bad != -1) reject = 1;
                bad = i;
                need = B[i] - A[i];
            } else {
                margin = min(margin, A[i] - B[i]);
            }
        }
        if (reject) {
            cout << "NO" << endl;
            continue;
        } else {
            cout << ((margin >= need) ? "YES" : "NO") << endl;
        }
    }
    }

int main(){
    fast();
    func();
    return 0;
}   