#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast() \
ios_base::sync_with_stdio(false); \
 cin.tie(NULL);

void func(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string result = string(k, '1') + string(n-k, '0');
        cout << result << "\n";
    }
}

int main(){
    fast();
    func();
    return 0;
}