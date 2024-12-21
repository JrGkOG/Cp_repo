#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main(){
    fast();
    int t;
    cin >> t;
    vector<int> ans;
    while (t--) {
        int number;
        cin >> number;
        int countOfO = 0; 
        int prev=-1;
        int subArraySize=0;
        int nonZero=0;
        int tempSub=0;
        for (int i = 0; i < number; i++) {
            int n;
            cin >> n;
            if (n == 0) {
                subArraySize=max(tempSub,subArraySize);
                tempSub=0;
                prev=0; 
                countOfO++;
            }
            else{
                nonZero++;
                tempSub++;
                subArraySize=max(tempSub,subArraySize);
                prev=n;
            }
        }
        if (countOfO == number) {
            ans.push_back(0);
        } else {
            if(subArraySize==nonZero){
                ans.push_back(1);
            }
            else{
                ans.push_back(2);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}